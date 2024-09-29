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
    {CRGB::Red, {CRGB::Green, CRGB::Blue, CRGB::Cyan}},
    {CRGB::Green, {CRGB::Red, CRGB::Blue, CRGB::Purple, CRGB::Orange}},
    {CRGB::Blue, {CRGB::Red, CRGB::Yellow, CRGB::Orange}},
    {CRGB::Yellow, {CRGB::Blue, CRGB::Purple, CRGB::Cyan}},
    {CRGB::Purple, {CRGB::Green, CRGB::Yellow, CRGB::Cyan, CRGB::Orange}},
    {CRGB::Cyan, {CRGB::Red, CRGB::Yellow, CRGB::Purple}},
    {CRGB::Orange, {CRGB::Green, CRGB::Blue, CRGB::Purple}}
};

// Advanced Colors (excluding white)
const std::vector<CRGB> advancedColors = {
    CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::Yellow, 
    CRGB::Purple, CRGB::Cyan, CRGB::Orange,
    CRGB::Pink, CRGB::Magenta, CRGB::Lime, CRGB::Turquoise, 
    CRGB::Violet, CRGB::Gold, CRGB::Silver, CRGB::Brown
};

const std::map<CRGB, std::vector<CRGB>> advancedColorMapping = {
    {CRGB::Red, {CRGB::Green, CRGB::Blue, CRGB::Cyan, CRGB::Pink, CRGB::Turquoise}},
    {CRGB::Green, {CRGB::Red, CRGB::Blue, CRGB::Purple, CRGB::Orange, CRGB::Lime, CRGB::Gold}},
    {CRGB::Blue, {CRGB::Red, CRGB::Yellow, CRGB::Orange, CRGB::Magenta, CRGB::Silver}},
    {CRGB::Yellow, {CRGB::Blue, CRGB::Purple, CRGB::Cyan, CRGB::Lime, CRGB::Brown}},
    {CRGB::Purple, {CRGB::Green, CRGB::Yellow, CRGB::Cyan, CRGB::Orange, CRGB::Violet, CRGB::Gold}},
    {CRGB::Cyan, {CRGB::Red, CRGB::Yellow, CRGB::Purple, CRGB::Turquoise, CRGB::Silver}},
    {CRGB::Orange, {CRGB::Green, CRGB::Blue, CRGB::Purple, CRGB::Brown, CRGB::Gold}},
    {CRGB::Pink, {CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::Yellow, CRGB::Magenta, CRGB::Turquoise}},
    {CRGB::Magenta, {CRGB::Red, CRGB::Blue, CRGB::Yellow, CRGB::Pink, CRGB::Silver}},
    {CRGB::Lime, {CRGB::Green, CRGB::Yellow, CRGB::Cyan, CRGB::Turquoise, CRGB::Gold}},
    {CRGB::Turquoise, {CRGB::Red, CRGB::Green, CRGB::Cyan, CRGB::Pink, CRGB::Lime}},
    {CRGB::Violet, {CRGB::Purple, CRGB::Yellow, CRGB::Cyan, CRGB::Orange, CRGB::Gold, CRGB::Silver}},
    {CRGB::Gold, {CRGB::Green, CRGB::Purple, CRGB::Orange, CRGB::Lime, CRGB::Violet}},
    {CRGB::Silver, {CRGB::Blue, CRGB::Cyan, CRGB::Magenta, CRGB::Turquoise, CRGB::Violet}},
    {CRGB::Brown, {CRGB::Yellow, CRGB::Orange, CRGB::Gold, CRGB::Silver, CRGB::Violet}}
};

// Color Variations
const std::vector<CRGB> redVariations = {
    CRGB::Red, CRGB::DarkRed, CRGB::IndianRed, CRGB::LightCoral, CRGB::Salmon
};

const std::vector<CRGB> greenVariations = {
    CRGB::Green, CRGB::DarkGreen, CRGB::LimeGreen, CRGB::PaleGreen, CRGB::SpringGreen
};

const std::vector<CRGB> blueVariations = {
    CRGB::Blue, CRGB::DarkBlue, CRGB::LightBlue, CRGB::SkyBlue, CRGB::SteelBlue
};

#endif