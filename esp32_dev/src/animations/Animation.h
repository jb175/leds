#ifndef ANIMATION_H
#define ANIMATION_H

#include <Arduino.h>
#include <FastLED.h>
#include <vector>

class Animation {
public:
    Animation(CRGB color, unsigned long duration, unsigned int times)
        : color_(color), duration_(duration), times_(times) {}
    virtual ~Animation() = default;
    virtual std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed) = 0;
    CRGB getColor() const { return color_; }
    unsigned long getDuration() const { return duration_; }
    bool getIsFinished(unsigned long timeElapsed) const {
        return (timeElapsed > duration_*times_);
     };
private:
    CRGB color_;
    unsigned long duration_;
    unsigned int times_;
};

#endif