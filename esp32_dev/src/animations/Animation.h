#ifndef ANIMATION_H
#define ANIMATION_H

#include <Arduino.h>
#include <FastLED.h>
#include <vector>

class Animation {
public:
    Animation(CRGB color, unsigned long duration) {
        this->setColor(color);
        this->setDuration(duration);
    }
    virtual ~Animation() = default;
    virtual std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed) = 0;
    CRGB getColor() const { return color_; }
    unsigned long getDuration() const { return duration_; }
    void setColor(CRGB color) { this->color_ = color; }
    void setDuration(unsigned long duration) { this->duration_ = duration; }
private:
    CRGB color_;
    unsigned long duration_;
};

#endif