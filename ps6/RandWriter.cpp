// Copyright 2021 Anurag Akella
#include "RandWriter.h"
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <string>
#include <stdexcept>
#include <vector>
#include <utility>

RandWriter::RandWriter(std::string text, int k) {
  RandWriter::k = k;
  std::map<std::string, int>::iterator it;
  RandWriter::text = text;

  if (text.length() < (unsigned)k) {
    throw std::runtime_error("Error.RandWriter.RandWriter -"
      " length of text should be > than k");
  }

  std::map<char, int> duplicates;
  for (int i = 0; i < static_cast<int>(text.length()); i++) {
    char tmp = text.at(i);

    if (!duplicates.count(tmp)) {
      alpha.push_back(tmp);
      duplicates[tmp] = 1;
    }
  }
  std::sort(alpha.begin(), alpha.end());
  int pos = 0;
    for (int i = 0; i < static_cast<int>(text.length()); i++) {
        std::string kgram;
        std::map<char, int> ftable;
        for (int j = i; j < i + k; j++) {
            pos = j >= static_cast<int>(text.length()) ? \
              j - static_cast<int>(text.length()) : j;
            kgram += text.at(pos);
        }
        pos++;
        if (pos >= static_cast<int>(text.length())) \
          pos -= static_cast<int>(text.length());
        ftable.insert(std::make_pair(text.at(pos), 0));

        if (ktable.count(kgram) == 0) {
            ktable.insert(std::make_pair(kgram, ftable));
        }

        ktable[kgram][text.at(pos)]++;
    }
}

int RandWriter::order_k() {
  return [=]() -> int {
    return k;
  }();
}

int RandWriter::freq(std::string k_gram) {
  if (k_gram.length() != (unsigned)k) {
    throw std::runtime_error("Error.RandWriter.freq - kgram not of length k.");
  }

  int count = 0;
    for (int i = 0; i < static_cast<int>(text.length()); i++) {
      int pos = 0;
        std::string kg;
        for (int j = i; j < i + k; j++) {
            pos = j >= static_cast<int>(text.length()) ? j - text.length() : j;
            kg += text.at(pos);
        }
        if (k_gram == kg) count++;
    }
    return count;
}

int RandWriter::freq(std::string k_gram, char c) {
  if (k_gram.length() != (unsigned)k) {
    throw std::runtime_error("Error.RandWriter.freq - kgram not of length k.");
  }
  try {
    return ktable.at(k_gram).at(c);
  } catch (std::out_of_range &e) {
    return 0;
  }
}

char RandWriter::k_Rand(std::string k_gram) {
  if (k_gram.length() != (unsigned)k) {
    throw std::runtime_error("Error.RandWriter.k_Rand -"
      " kgram not of length k.");
  }

  std::map<std::string, std::map<char, int>>::iterator it;
  it = ktable.find(k_gram);
  std::string outx = "";
  for (auto const &var2 : it -> second) {
    outx += var2.first;
  }
  unsigned int seed = 100;
  int r = rand_r(&seed) % outx.length();
  return outx.at(r);
}

std::string RandWriter::generate(std::string k_gram, int L) {
  if (k_gram.length() != (unsigned)k) {
    throw std::runtime_error("Error.RandWriter.generate -"
    " kgram not of length k.");
  }
  for (int i = k; i < L; i++) k_gram += k_Rand(k_gram.substr(i - k, k));
  return k_gram;
}

std::ostream &operator<<(std::ostream &out, RandWriter &randWriter ) {
  out << "Original Text: " << randWriter.text << std::endl;
  out << "Markov Order: " << randWriter.k << std::endl;
  out << "Frequency Map: " << std::endl;

  std::map<std::string, std::map<char, int>>::iterator it;

  for (it = randWriter.ktable.begin(); it != randWriter.ktable.end(); it++) {
    out << it->first << ":" << "\n";
    for (auto const &var2 : it -> second)
     out << "\t" << var2.first << ": " << var2.second << "\n";
  }

  return out;
}
