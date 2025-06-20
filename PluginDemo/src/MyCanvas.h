//
// Created by javiolonchelo on 24/04/2025.
//

#ifndef MYCANVAS_H
#define MYCANVAS_H

#include "CustomLookAndFeel.h"
#include "CustomColours.h"
#include "common.h"
#include "juce_gui_basics/juce_gui_basics.h"

using namespace juce;

class MyCanvas : public Component {
 public:
  explicit MyCanvas();
  void paint(Graphics& g) override;

 private:

  // Mouse callbacks
  void mouseDoubleClick(const MouseEvent&) override;
  void mouseDrag(const MouseEvent&) override;
  void mouseUp(const MouseEvent&) override;
  void mouseDown(const MouseEvent&) override;
  void mouseWheelMove(const MouseEvent&, const MouseWheelDetails&) override;
};

#endif  // MYCANVAS_H
