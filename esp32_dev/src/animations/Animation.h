#ifndef ANIMATION_H
#define ANIMATION_H

#include <Arduino.h>
#include <FastLED.h>
#include <vector>

class Animation {
public:
    Animation(CRGB color, unsigned long duration, unsigned int times) {
        this->setColor(color);
        this->setDuration(duration);
        this->times_ = times;
    }
    virtual ~Animation() = default;
    virtual std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed) = 0;
    CRGB getColor() const { return color_; }
    unsigned long getDuration() const { return duration_; }
    void setColor(CRGB color) { this->color_ = color; }
    void setDuration(unsigned long duration) { this->duration_ = duration; }
    void colorNscale8(uint8_t scaledown) { color_.nscale8(scaledown); }
    bool getIsFinished() const { return isFinished_; };
protected:
    void checkIsFinished(unsigned long timeElapsed) {
        if (timeElapsed > duration_*times_) {
            isFinished_ = true;
        }
    }
private:
    CRGB color_;
    unsigned long duration_;
    unsigned int times_;
    bool isFinished_ = false;
};

#endif