#ifndef TRANSITION_PARAMS_H
#define TRANSITION_PARAMS_H

#include <Arduino.h>

enum class Direction {
    Left,
    Right,
    Random
};

class TransitionParams {
public:
    unsigned long duration;
    Direction direction;

    TransitionParams(unsigned long duration, Direction direction = Direction::Random)
        : duration(duration), direction(direction) {}
};

#endif