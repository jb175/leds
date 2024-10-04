#ifndef ANIMATION_PARAMS_H
#define ANIMATION_PARAMS_H

#include <Arduino.h>
#include <FastLED.h>

enum class Direction {
    FromCable,
    Opposite,
    Random
};

class AnimationParams {
public:
    CRGB color;
    unsigned long duration;
    std::pair<int, int> timesToRepeat;
    Direction direction;
    
    AnimationParams(CRGB color, unsigned long duration)
        : color(color), duration(duration), timesToRepeat(std::pair<int, int> {1, 1}), direction(Direction::Random) {}

    AnimationParams(CRGB color, unsigned long duration, std::pair<int, int> timesToRepeat, Direction direction = Direction::Random)
        : color(color), duration(duration), timesToRepeat(timesToRepeat), direction(direction) {}
};

#endif