// UPM 2025
// Javier Rodrigo López
// javier.rlopez@alumnos.upm.es

#pragma once

#include "CustomLookAndFeel.h"
#include "Knob.h"
#include "MyCanvas.h"
#include "PluginProcessor.h"
#include "TitleBox.h"
#include "common.h"

class GainAudioProcessorEditor : public AudioProcessorEditor, private AudioProcessorValueTreeState::Listener {
 public:
  // Basic
  explicit GainAudioProcessorEditor(GainAudioProcessor&);
  ~GainAudioProcessorEditor() override;
  void paint(Graphics&) override;
  void resized() override;

 private:
  // Mouse callbacks
  void mouseDoubleClick(const MouseEvent&) override;
  void mouseDrag(const MouseEvent&) override;
  void mouseUp(const MouseEvent&) override;
  void mouseDown(const MouseEvent& event) override;
  void mouseWheelMove(const MouseEvent&, const MouseWheelDetails&) override;

  // Member variables
  GainAudioProcessor&       audioProcessor;
  CustomLookAndFeel         customLookAndFeel;
  std::unique_ptr<MyCanvas> myCanvas;
  std::unique_ptr<Knob>     knob;
  std::unique_ptr<TitleBox> titleComponent;

  Point<int>   lastCenter             = {STARTUP_CENTER, STARTUP_CENTER};
  Point<float> posWhenStartedDragging = {0.0f, 0.0f};

  // APVTS
  std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> knobAttachment;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GainAudioProcessorEditor)
 public:
  void parameterChanged(const String& parameterID, float newValue) override;
};
