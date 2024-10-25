#ifndef ANIMATIONLIST_H
#define ANIMATIONLIST_H

#include <Arduino.h>
#include <FastLED.h>
#include <vector>
#include <utility>
#include <map>
#include <animations/Animation.h>
#include <transitions/Transition.h>

enum class AnimationType {
    Glow,
    Breathing,
    RainbowPulse,
    BlinkingStars,
    Waves,
    BasicColor
};

enum class TransitionType {
    NoTransition,
    SlideTransition,
    ColorFadeTransition
};

class AnimationList {
public:
    AnimationList(
        std::vector<std::pair<AnimationType, int>> const& animationProbabilities,
        std::vector<std::pair<TransitionType, int>> const& transitionProbabilities
    ) : animationProbabilities_(animationProbabilities), transitionProbabilities_(transitionProbabilities) {};
    
    virtual ~AnimationList() = default;
    virtual void createNewTransition() = 0;
    virtual void createNewAnimation() = 0;

    /**
     * @brief Selects a random item from a list of items with associated probabilities.
     *
     * This function takes a vector of pairs, where each pair consists of an item and its associated probability weight.
     * It returns one of the items, selected randomly according to the given probabilities.
     *
     * @tparam T The type of the items in the list.
     * @param items A vector of pairs, where each pair contains an item of type T and an int representing its probability weight.
     * @return T The randomly selected item.
     */
    template <typename T> T selectRandomWithProbability(const std::vector<std::pair<T, int>>& items) {
        int totalWeight = 0;
        for (const auto& item : items) {
            totalWeight += item.second;
        }

        int randomValue = random(0, totalWeight);
        for (const auto& item : items) {
            if (randomValue <= item.second) {
                return item.first;
            }
            randomValue -= item.second;
        }

        return items.back().first; // Fallback
    }

    
    /**
     * @brief Generates a new color based on the provided color mapping.
     *
     * This function takes a map of CRGB colors to vectors of CRGB colors and generates a new color.
     * If the current color is found in the map, it recursively generates a new color from the associated vector.
     * If the current color is not found in the map, it randomly selects a new color from the keys of the map.
     *
     * @param colorMapping A map where the keys are CRGB colors and the values are vectors of CRGB colors.
     * @return A new CRGB color.
     */
    CRGB generateNewColor(const std::map<CRGB, std::vector<CRGB>>& colorMapping) {
        if (colorMapping.find(currentColor_) != colorMapping.end()) {
            return generateNewColor(colorMapping.at(currentColor_));
        } else {
            auto it = colorMapping.begin();
            std::advance(it, random(0, colorMapping.size()));
            return it->first;
        }
    }

    /**
     * @brief Generates a new color based on the provided color list.
     *
     * This function takes a vector of CRGB colors and generates a new color.
     * If the list contains only one color, that color is returned.
     * If the list contains multiple colors, a new color is randomly selected from the list.
     *
     * @param colorList A vector of CRGB colors.
     * @return A new CRGB color.
     */
    CRGB generateNewColor(const std::vector<CRGB>& colorList) {
        if (colorList.size() <= 1) {
            return colorList[0];
        }
        CRGB newColor;
        do {
            newColor = colorList[random(0, colorList.size())];
        } while (newColor == currentColor_);
        return newColor;
    }


    /**
     * @brief Runs the animation list.
     *
     * This function runs the animation list by generating animations and transitions based on the current state.
     * It updates the LED strip with the generated colors and transitions.
     *
     * @param leds An array of CRGB colors representing the LED strip.
     * @param numLeds The number of LEDs in the strip.
     * @param timeElapsed The time elapsed since the program started.
     */
    void runAnimationList(CRGB* leds, int numLeds, unsigned long timeElapsed) {
        // Transition
        if (transition_ != nullptr) {
            unsigned long transitionElapsed = timeElapsed - transitionStartTime_;

            if (transitionElapsed >= transition_->getDuration()) {
                // Close transition
                delete transition_;
                transition_ = nullptr;
                lastIntervalChange_ = timeElapsed;
            } else {
                std::vector<CRGB> ledStates = transition_->generateLEDs(numLeds, transitionElapsed);

                for (int i = 0; i < numLeds; i++) {
                    leds[i] = ledStates[i];
                }

                FastLED.show();
                return;
            }
        }

        // Animation
        unsigned long intervalElapsed = timeElapsed - lastIntervalChange_;
        if (currentAnimation_->getIsFinished(intervalElapsed)) {
            // Finish animation
            createNewTransition();
            lastIntervalChange_ = timeElapsed;
        } else if (currentAnimation_ != nullptr) {
            std::vector<CRGB> ledStates = currentAnimation_->generateLEDs(numLeds, intervalElapsed);

            for (int i = 0; i < numLeds; i++) {
                leds[i] = ledStates[i];
            }

            FastLED.show();
        } else {
            createNewAnimation();
        }
    }

    // Getters and setters
    Animation* getCurrentAnimation() const {
        return currentAnimation_;
    }
    void setCurrentAnimation(Animation* animation) {
        currentAnimation_ = animation;
    }
    Animation* getPreviousAnimation() const {
        return previousAnimation_;
    }
    void setPreviousAnimation(Animation* animation) {
        if (previousAnimation_ != nullptr) {
            delete previousAnimation_;
        }
        previousAnimation_ = animation;
    }
    Transition* getTransition() const {
        return transition_;
    }
    void setTransition(Transition* transition) {
        if (transition_ != nullptr) {
            delete transition_;
        }
        transition_ = transition;
    }
    unsigned long getLastIntervalChange() const {
        return lastIntervalChange_;
    }
    void setLastIntervalChange(unsigned long lastIntervalChange) {
        lastIntervalChange_ = lastIntervalChange;
    }
    unsigned long getTransitionStartTime() const {
        return transitionStartTime_;
    }
    void setTransitionStartTime(unsigned long transitionStartTime) {
        transitionStartTime_ = transitionStartTime;
    }
    CRGB getLastColor() const {
        return lastColor_;
    }
    void setLastColor(CRGB lastColor) {
        lastColor_ = lastColor;
    }
    CRGB getCurrentColor() const {
        return currentColor_;
    }
    void setCurrentColor(CRGB currentColor) {
        currentColor_ = currentColor;
    }
    std::vector<std::pair<AnimationType, int>> getAnimationProbabilities() const {
        return animationProbabilities_;
    }
    std::vector<std::pair<TransitionType, int>> getTransitionProbabilities() const {
        return transitionProbabilities_;
    }
    
    String getCurrentAnimationName() const {
        if (getCurrentAnimation() == nullptr) {
            return "None";
        }
        return String(typeid(*getCurrentAnimation()).name());
    }
    String getCurrentAnimationParams() const {
        if (getCurrentAnimation() == nullptr) {
            return "None";
        }
        String params = "Color: " + String(getCurrentAnimation()->getColor().r) + ", " +
                        String(getCurrentAnimation()->getColor().g) + ", " +
                        String(getCurrentAnimation()->getColor().b) + "\n";
        params += "Duration: " + String(getCurrentAnimation()->getDuration()) + "\n";
        return params;
    }

private:
    Animation* currentAnimation_ = nullptr;
    Animation* previousAnimation_ = nullptr;
    Transition* transition_ = nullptr;

    unsigned long lastIntervalChange_ = 0;
    unsigned long transitionStartTime_ = 0;

    CRGB lastColor_;
    CRGB currentColor_;

    std::vector<std::pair<AnimationType, int>> animationProbabilities_;
    std::vector<std::pair<TransitionType, int>> transitionProbabilities_;
};

#endif