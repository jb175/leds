# Boîtier d'Alimentation pour LED WS2812B

Ce projet a pour objectif de créer un boîtier d'alimentation et de contrôle pour des bandes LED WS2812B. Il inclut une partie électronique, un code pour ESP32 et une interface de contrôle (web ou mobile).

## Table des matières

1. [Introduction](#introduction)
2. [Schémas électroniques](#schémas-électroniques)
3. [Code pour l'ESP32](#code-pour-lesp32)
4. [Contrôle via site web ou app](#contrôle-via-site-web-ou-app)
5. [Installation et tests](#installation-et-tests)
6. [Contributions](#contributions)

---

## Introduction

Le projet permet de contrôler des bandes LED WS2812B avec différentes animations lumineuses basées sur la musique. L'objectif est également de permettre le contrôle via une interface web ou mobile.

## Schémas électroniques

Les schémas électroniques du circuit sont disponibles dans le dossier [hardware](./hardware). Voici un aperçu du schéma principal :

![Schéma électronique](./images/schema_electronique.png)

## Code pour l'ESP32

Le code source pour l'ESP32 est disponible dans le dossier [code](./code). Vous y trouverez également des instructions pour installer les bibliothèques nécessaires et flasher l'ESP32.

## Contrôle via site web ou app

La documentation pour la création de l'interface de contrôle (site web ou application mobile) est disponible dans le dossier [docs/web_app](./docs/web_app).

## Installation et tests

Instructions détaillées pour assembler le matériel et tester le projet avec votre bande LED.

1. Branchez les composants selon le schéma électronique.
2. Flash le code sur l'ESP32...
3. Test des animations.

## Contributions

Les contributions sont les bienvenues ! Veuillez consulter la section [Contributions](./docs/contributions.md) pour plus de détails.