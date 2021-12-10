// Copyright 2021 Anurag Akella
#include <math.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "StringSound.h"

#define CONCERT_A 440.0
#define SAMPLES_PER_SEC 44100

std::vector<sf::Int16> makeSamples(StringSound *gs) {
  std::vector<sf::Int16> samples;
  gs -> pluck();
  int duration = 8;  // seconds
  int i;
  for (i= 0; i < SAMPLES_PER_SEC * duration; i++) {
    gs -> tic();
    samples.push_back(gs -> sample());
  }

  return samples;
}

int main() {
  sf::RenderWindow window(sf::VideoMode(500, 500),
    "SFML Plucked String Sound Lite");
  window.setFramerateLimit(60);

  sf::Event event;
  std::vector<sf::Int16> sample;
  double freq = CONCERT_A;

  std::string keyboardString = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";
  std::vector<sf::Sound> sounds(123);
  std::vector<sf::SoundBuffer> buffers(keyboardString.size());

  for (int i = 0; i < keyboardString.size(); i++) {
    sounds[static_cast<int>(keyboardString[i])] = sf::Sound();
    freq = CONCERT_A * pow(2, (i-24)/12.0);
    StringSound gs = StringSound(freq);
    sample = makeSamples(&gs);
    if (!buffers[i].loadFromSamples(&sample[0],
        sample.size(), 2, SAMPLES_PER_SEC))
        throw std::runtime_error(
          "sf::SoundBuffer: failed to l ad from samples.");
    sounds[static_cast<int>(keyboardString[i])].setBuffer(buffers[i]);
  }

  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;

      case sf::Event::TextEntered:
        sounds[event.text.unicode].play();

        window.clear();
        window.display();
      }
    }
  }
  return 0;
}


