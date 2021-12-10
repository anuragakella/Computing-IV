// Copyright 2021 Anurag Akella
#include "StringSound.h"
#include <math.h>
#include <random>

#define SAMPLING_RATE 44100
#define DECAY_FACTOR 0.996
#define M_PI 3.14159265358979323846

StringSound::StringSound(double frequency) {
    blen = ceil(SAMPLING_RATE/frequency);
    buffer = new CircularBuffer(blen);
    for (int i = 0; i < blen; i++)
        buffer -> enqueue(0);
        // dont have to handle exceptions because the
        // loop doesn't run past the queue size.
    _time = 0;
}

void StringSound::pluck() {
    buffer -> empty();
    int16_t val = 0;
    for (int i = 1; i <= blen; i++) {
        try {
            buffer->enqueue(10000*sin(2 * M_PI * i/blen));
        } catch(const char* msg) {
            std::cout << msg << std::endl;
        }
    }
}

void StringSound::tic() {
    int16_t val = 0;
    try {
        val = buffer -> dequeue();
    } catch(const char* msg) {
        std::cout << msg << std::endl;
    }
    int16_t ns = (val + buffer -> peek())/ 2 * DECAY_FACTOR;
    buffer -> enqueue(int16_t(ns));
    _time++;
}

int StringSound::time() {
    return _time;
}

sf::Int16 StringSound::sample() {
    try {
       return buffer -> peek();
    } catch(const char* msg) {
        std::cout << msg << std::endl;
    }
    return 0;
}

StringSound::~StringSound() {}
