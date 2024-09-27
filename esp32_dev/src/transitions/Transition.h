#ifndef TRANSITION_H
#define TRANSITION_H

#include <FastLED.h>
#include <vector>
#include <animations/soft/SoftAnimation.h>

class Transition {
public:
    Transition(SoftAnimation* from, SoftAnimation* to, unsigned long duration) {
        this->setFrom(from);
        this->setTo(to);
        this->setDuration(duration);
        this->setStartTime(millis());
    }
    virtual ~Transition() = default;
    virtual std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed) = 0;
    SoftAnimation* getFrom() const { return from_; }
    SoftAnimation* getTo() const { return to_; }
    unsigned long getDuration() const { return duration_; }
    unsigned long getStartTime() const { return startTime_;}
    void setFrom(SoftAnimation* from) { this->from_ = from; }
    void setTo(SoftAnimation* to) { this->to_ = to; }
    void setDuration(unsigned long duration) { this->duration_ = duration; }
    void setStartTime(unsigned long startTime) { this->startTime_ = startTime; }
private:
    SoftAnimation* from_;
    SoftAnimation* to_;
    unsigned long duration_;
    unsigned long startTime_;
};

#endif // TRANSITION_H