#ifndef TRANSITION_H
#define TRANSITION_H

#include <FastLED.h>
#include <vector>
#include <animations/calm/CalmAnimation.h>

class Transition {
public:
    Transition(CalmAnimation* from, CalmAnimation* to, unsigned long duration) {
        this->setFrom(from);
        this->setTo(to);
        this->setDuration(duration);
        this->setStartTime(millis());
    }
    virtual ~Transition() = default;
    virtual std::vector<CRGB> generateLEDs(int numLeds, unsigned long timeElapsed) = 0;
    CalmAnimation* getFrom() const { return from_; }
    CalmAnimation* getTo() const { return to_; }
    unsigned long getDuration() const { return duration_; }
    unsigned long getStartTime() const { return startTime_;}
    void setFrom(CalmAnimation* from) { this->from_ = from; }
    void setTo(CalmAnimation* to) { this->to_ = to; }
    void setDuration(unsigned long duration) { this->duration_ = duration; }
    void setStartTime(unsigned long startTime) { this->startTime_ = startTime; }
private:
    CalmAnimation* from_;
    CalmAnimation* to_;
    unsigned long duration_;
    unsigned long startTime_;
};

#endif // TRANSITION_H