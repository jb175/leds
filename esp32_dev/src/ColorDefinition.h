#ifndef COLOR_DEFINITIONS_H
#define COLOR_DEFINITIONS_H

#include <FastLED.h>
#include <map>
#include <vector>

// Basic Colors (excluding white)
const std::vector<CRGB> basicColors = {
    CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::Yellow, 
    CRGB::Purple, CRGB::Cyan, CRGB::Orange
};

const std::map<CRGB, std::vector<CRGB>> basicColorMapping = {
    {CRGB::Red, {CRGB::Green, CRGB::Blue, CRGB::Yellow}},
    {CRGB::Green, {CRGB::Red, CRGB::Blue, CRGB::Purple}},
    {CRGB::Blue, {CRGB::Red, CRGB::Yellow, CRGB::Orange}},
    {CRGB::Yellow, {CRGB::Blue, CRGB::Purple, CRGB::Cyan}},
    {CRGB::Purple, {CRGB::Green, CRGB::Yellow, CRGB::Orange}},
    {CRGB::Cyan, {CRGB::Red, CRGB::Yellow, CRGB::Purple}},
    {CRGB::Orange, {CRGB::Green, CRGB::Blue, CRGB::Purple}}
};

// Advanced Colors (excluding white and black)
const std::vector<CRGB> advancedColors = {
    CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::Yellow, 
    CRGB::Purple, CRGB::Cyan, CRGB::Orange,
    CRGB::Pink, CRGB::Magenta, CRGB::Lime, CRGB::Turquoise, 
    CRGB::Violet, CRGB::Gold, CRGB::Silver, CRGB::Brown
};

const std::map<CRGB, std::vector<CRGB>> advancedColorMapping = {
    {CRGB::Red, {CRGB::Green, CRGB::Blue, CRGB::Yellow, CRGB::Cyan, CRGB::Magenta, CRGB::Orange}},
    {CRGB::Green, {CRGB::Red, CRGB::Blue, CRGB::Yellow, CRGB::Purple, CRGB::Orange, CRGB::Pink}},
    {CRGB::Blue, {CRGB::Red, CRGB::Green, CRGB::Yellow, CRGB::Orange, CRGB::Pink, CRGB::Magenta}},
    {CRGB::Yellow, {CRGB::Blue, CRGB::Purple, CRGB::Red, CRGB::Green, CRGB::Cyan, CRGB::Pink}},
    {CRGB::Purple, {CRGB::Green, CRGB::Yellow, CRGB::Red, CRGB::Blue, CRGB::Orange, CRGB::Cyan}},
    {CRGB::Cyan, {CRGB::Red, CRGB::Yellow, CRGB::Purple, CRGB::Green, CRGB::Orange, CRGB::Pink}},
    {CRGB::Orange, {CRGB::Green, CRGB::Blue, CRGB::Yellow, CRGB::Red, CRGB::Purple, CRGB::Cyan}},
    {CRGB::Pink, {CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::Yellow, CRGB::Orange, CRGB::Purple}},
    {CRGB::Magenta, {CRGB::Red, CRGB::Blue, CRGB::Yellow, CRGB::Green, CRGB::Orange, CRGB::Pink}},
    {CRGB::Lime, {CRGB::Blue, CRGB::Yellow, CRGB::Red, CRGB::Purple, CRGB::Orange, CRGB::Cyan}},
    {CRGB::Turquoise, {CRGB::Red, CRGB::Green, CRGB::Yellow, CRGB::Purple, CRGB::Orange, CRGB::Pink}},
    {CRGB::Violet, {CRGB::Purple, CRGB::Yellow, CRGB::Red, CRGB::Green, CRGB::Orange, CRGB::Cyan}},
    {CRGB::Gold, {CRGB::Green, CRGB::Purple, CRGB::Red, CRGB::Yellow, CRGB::Blue, CRGB::Cyan}},
    {CRGB::Silver, {CRGB::Blue, CRGB::Yellow, CRGB::Red, CRGB::Green, CRGB::Orange, CRGB::Purple}},
    {CRGB::Brown, {CRGB::Yellow, CRGB::Orange, CRGB::Red, CRGB::Green, CRGB::Purple, CRGB::Cyan}}
};

#endif