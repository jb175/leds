#ifndef TRANSITION_H
#define TRANSITION_H

#include <FastLED.h>
#include <vector>
#include <animations/Animation.h>

class Transition {
public:
    Transition(Animation* from, Animation* to, unsigned long duration) {
        this->setFrom(from);
        this->setTo(to);
        this->setDuration(duration);
        this->setStartTime(millis());
    }
    virtual ~Transition() = default;
    virtual std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed) = 0;
    Animation* getFrom() const { return from_; }
    Animation* getTo() const { return to_; }
    unsigned long getDuration() const { return duration_; }
    unsigned long getStartTime() const { return startTime_;}
    void setFrom(Animation* from) { this->from_ = from; }
    void setTo(Animation* to) { this->to_ = to; }
    void setDuration(unsigned long duration) { this->duration_ = duration; }
    void setStartTime(unsigned long startTime) { this->startTime_ = startTime; }
private:
    Animation* from_;
    Animation* to_;
    unsigned long duration_;
    unsigned long startTime_;
};

#endif // TRANSITION_H