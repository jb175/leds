#include <Arduino.h>
#include <FastLED.h>
#include "leds.h"
#include "animations.h"

// Inclure les fichiers d'animation
// #include "animations/calme/lueur_douce.cpp"
// #include "animations/calme/changement_de_teinte.cpp"
// #include "animations/ambiance/vague_de_couleurs.cpp"
// #include "animations/ambiance/etoiles_clignotantes.cpp"
// #include "animations/dynamique/changement_de_couleurs.cpp"
// #include "animations/dynamique/pulsation_de_couleurs.cpp"
// #include "animations/energetique/course_de_lumiere.cpp"
// #include "animations/energetique/effect_de_flash.cpp"
// #include "animations/stroboscope/stroboscope_classique.cpp"
// #include "animations/stroboscope/flash_multicolore.cpp"

CRGB leds[NUM_LEDS];

// Définir les catégories
enum Category { CALME, AMBIANCE, DYNAMIQUE, ENERGETIQUE, STROBOSCOPE };
Category currentCategory;

// Fonction pour choisir une animation aléatoire dans la catégorie actuelle
void choisirAnimation(unsigned long duration) {
    int choix;
    switch (currentCategory) {
        case CALME:
            choix = random(0, 2); // 2 animations
            switch (choix) {
                case 0: lueurDouce(duration); break;
                case 1: changementDeTeinte(duration); break;
            }
            break;

        case AMBIANCE:
            choix = random(0, 2); // 2 animations
            switch (choix) {
                case 0: vagueDeCouleurs(duration); break;
                case 1: etoilesClignotantes(duration); break;
            }
            break;

        case DYNAMIQUE:
            choix = random(0, 2); // 2 animations
            switch (choix) {
                case 0: changementDeCouleurs(duration); break;
                case 1: pulsationDeCouleurs(duration); break;
            }
            break;

        case ENERGETIQUE:
            choix = random(0, 2); // 2 animations
            switch (choix) {
                case 0: courseDeLumiere(duration); break;
                case 1: effectDeFlash(duration); break;
            }
            break;

        case STROBOSCOPE:
            choix = random(0, 2); // 2 animations
            switch (choix) {
                case 0: stroboscopeClassique(duration); break;
                case 1: flashMulticolore(duration); break;
            }
            break;
    }
}

void setup() {
    // Initialisation
    FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
    randomSeed(analogRead(0)); // Initialiser le générateur de nombres aléatoires

    // Choisir une catégorie aléatoire
    currentCategory = static_cast<Category>(random(0, 5)); // 5 catégories
}

void loop() {
    unsigned long duration = random(8000, 10000); // Durée aléatoire entre 8 et 10 secondes
    currentCategory = static_cast<Category>(random(0, 5)); // 5 catégories
    choisirAnimation(duration); // Choisir et exécuter une animation pendant la durée définie
}
