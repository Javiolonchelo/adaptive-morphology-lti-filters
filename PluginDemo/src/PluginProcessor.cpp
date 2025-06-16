// dBob Studio 2025
// Javier Rodrigo López
// javiolonchelo@gmail.com

#include "PluginProcessor.h"

#include "PluginEditor.h"

AudioProcessorValueTreeState::ParameterLayout GainAudioProcessor::createParameterLayout() {
  std::vector<std::unique_ptr<RangedAudioParameter>> params;
  params.push_back(std::make_unique<AudioParameterFloat>(
      P_GAIN_ID, P_GAIN_NAME, NormalisableRange<float>(-30.0f, 30.0f, 0.01f), 0.0f));
  params.push_back(std::make_unique<AudioParameterBool>(P_BYPASS_ID, P_BYPASS_NAME, true));
  params.push_back(
      std::make_unique<AudioParameterFloat>(P_X_ID, P_X_NAME, NormalisableRange<float>(-1.0f, 2.0f, 0.001f), 0.5f));
  params.push_back(
      std::make_unique<AudioParameterFloat>(P_Y_ID, P_Y_NAME, NormalisableRange<float>(-1.0f, 2.0f, 0.001f), 0.5f));
  params.push_back(
      std::make_unique<AudioParameterFloat>(P_SIZE_ID, P_SIZE_NAME, NormalisableRange<float>(0.0f, 4.0f, 0.01f), 0.6f));
  return {params.begin(), params.end()};
}

GainAudioProcessor::GainAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
    : AudioProcessor(BusesProperties()
  #if !JucePlugin_IsMidiEffect
    #if !JucePlugin_IsSynth
                         .withInput("Input", AudioChannelSet::stereo(), true)
    #endif
                         .withOutput("Output", AudioChannelSet::stereo(), true)
  #endif
                         ),
      apvts(std::make_unique<AudioProcessorValueTreeState>(*this, nullptr, "PluginDemo", createParameterLayout()))
#endif
{
  for (int channel = 0; channel < 2; channel++) {
    filter_init(&foundFilter[channel]);
  }
}

GainAudioProcessor::~GainAudioProcessor() {}

const String GainAudioProcessor::getName() const { return JucePlugin_Name; }

bool GainAudioProcessor::acceptsMidi() const {
#if JucePlugin_WantsMidiInput
  return true;
#else
  return false;
#endif
}

bool GainAudioProcessor::producesMidi() const {
#if JucePlugin_ProducesMidiOutput
  return true;
#else
  return false;
#endif
}

bool GainAudioProcessor::isMidiEffect() const {
#if JucePlugin_IsMidiEffect
  return true;
#else
  return false;
#endif
}

double GainAudioProcessor::getTailLengthSeconds() const { return 0.0; }

int GainAudioProcessor::getNumPrograms() { return 1; }

int GainAudioProcessor::getCurrentProgram() { return 0; }

void GainAudioProcessor::setCurrentProgram(int) {}

const String GainAudioProcessor::getProgramName(int) { return {}; }

void GainAudioProcessor::changeProgramName(int, const String&) {}

void GainAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
  for (int channel = 0; channel < 2; channel++) {
    filter_reset(&foundFilter[channel]);
  }
  gain.reset(sampleRate, 0.005);
}

void GainAudioProcessor::releaseResources() {}

#ifndef JucePlugin_PreferredChannelConfigurations
bool GainAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const {
  #if JucePlugin_IsMidiEffect
  ignoreUnused(layouts);
  return true;
  #else
  if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono() &&
      layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
    return false;

    #if !JucePlugin_IsSynth
  if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet()) return false;
    #endif
  return true;
  #endif
}
#endif

void GainAudioProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages) {
  ScopedNoDenormals noDenormals;
  const auto        numIns  = getTotalNumInputChannels();
  const auto        numOuts = getTotalNumOutputChannels();
  const auto        N       = buffer.getNumSamples();

  gain.setTargetValue(apvts->getRawParameterValue(P_GAIN_ID)->load());
  auto currentGain = gain.getCurrentValue();

  for (auto i = numIns; i < numOuts; ++i)
    buffer.clear(i, 0, buffer.getNumSamples());

  for (int channel = 0; channel < numIns; channel++) {
    auto* y = buffer.getWritePointer(channel);
    for (int n = 0; n < N; n++) {
      filter_process(&foundFilter[channel], &y[n], &y[n], 1);
      if (channel == 0) { currentGain = gain.getCurrentValue(); }
      y[n] *= Decibels::decibelsToGain(currentGain);
    }
  }
}

bool GainAudioProcessor::hasEditor() const { return true; }

AudioProcessorEditor* GainAudioProcessor::createEditor() { return new GainAudioProcessorEditor(*this); }

void GainAudioProcessor::getStateInformation(MemoryBlock&) {}

void GainAudioProcessor::setStateInformation(const void* data, int sizeInBytes) {
  if (data != nullptr && sizeInBytes > 0) {
    MemoryInputStream stream(data, sizeInBytes, false);
    apvts->state = ValueTree::readFromStream(stream);
  }
}

AudioProcessor* JUCE_CALLTYPE createPluginFilter() { return new GainAudioProcessor(); }
