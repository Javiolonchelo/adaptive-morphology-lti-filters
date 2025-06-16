// dBob Studio 2025
// Javier Rodrigo López
// javiolonchelo@gmail.com

#include "CustomLookAndFeel.h"

#include "BinaryData.h"
#include "Knob.h"

CustomLookAndFeel::CustomLookAndFeel()
{
    knob = std::make_unique<Image>(ImageCache::getFromMemory(BinaryData::escudo_png, BinaryData::escudo_pngSize));
    jassert(knob != nullptr);
    jassert(knob->isValid());
}

CustomLookAndFeel::~CustomLookAndFeel() = default;

void CustomLookAndFeel::drawRotarySlider(Graphics &g, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle,
                                         float rotaryEndAngle, Slider &slider)
{
    const auto cocoPtr = dynamic_cast<Knob *>(&slider);
    jassert(cocoPtr != nullptr);

    const float centerX       = x + width / 2;
    const float centerY       = y + height / 2;
    const auto  rotationAngle = rotaryStartAngle + (rotaryEndAngle - rotaryStartAngle) * sliderPosProportional;
    g.addTransform(AffineTransform::rotation(rotationAngle, centerX, centerY));

    // This prevents the image from being drawn outside the bounds of the knob
    g.addTransform(AffineTransform::scale(0.9f, 0.9f, centerX, centerY));

    g.drawImage(*knob, x, y, width, height, 0, 0, knob->getWidth(), knob->getHeight(), false);
}

// Fonts
Typeface::Ptr CustomLookAndFeel::getTypefaceForFont(const Font &)
{
    return Typeface::createSystemTypefaceFor(BinaryData::JuliaMonoExtraBoldItalic_ttf, BinaryData::JuliaMonoExtraBoldItalic_ttfSize);
}
