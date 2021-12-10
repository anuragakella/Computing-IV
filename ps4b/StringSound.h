// Copyright 2021 Anurag Akella
#ifndef STRINGSOUND_H_
#define STRINGSOUND_H_
#include <vector>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "CircularBuffer.h"


class StringSound{
 public:
    explicit StringSound(double frequency);
    explicit StringSound(std::vector<sf::Int16> init);
    StringSound(const StringSound &obj) {}
    ~StringSound();
    void pluck();
    void tic();
    sf::Int16 sample();
    int time();

 private:
    CircularBuffer *buffer{};
    int _time;
    int blen;
};
#endif
