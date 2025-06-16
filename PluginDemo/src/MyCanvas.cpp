//
// Created by javiolonchelo on 24/04/2025.
//

#include "MyCanvas.h"
MyCanvas::MyCanvas() {
}
void MyCanvas::paint(Graphics& g) {
  g.fillAll(Colours::blue);
}

void MyCanvas::mouseDoubleClick(const MouseEvent& event) { getParentComponent()->mouseDoubleClick(event); }
void MyCanvas::mouseDrag(const MouseEvent& event) { getParentComponent()->mouseDrag(event); }
void MyCanvas::mouseUp(const MouseEvent& event) { getParentComponent()->mouseUp(event); }
void MyCanvas::mouseDown(const MouseEvent& event) { getParentComponent()->mouseDown(event); }
void MyCanvas::mouseWheelMove(const MouseEvent& event, const MouseWheelDetails& mouse_wheel_details) {
  getParentComponent()->mouseWheelMove(event, mouse_wheel_details);
}
