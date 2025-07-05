// UPM 2025
// Javier Rodrigo López
// javier.rlopez@alumnos.upm.es

#pragma once

#include "juce_audio_utils/juce_audio_utils.h"

using namespace juce;

class Knob : public Slider {
 public:
  // void paint(Graphics &) override;
  Knob();

  void mouseDoubleClick(const MouseEvent&) override;
  void mouseDrag(const MouseEvent&) override;
  void mouseDown(const MouseEvent&) override;
  void mouseUp(const MouseEvent&) override;
  void mouseWheelMove(const MouseEvent&, const MouseWheelDetails&) override;

 private:
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Knob)
};
