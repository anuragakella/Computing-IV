/*
 * Copyright 2021 Anurag Akella
 * All rights reserved.
 */
#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_
#include <stdint.h>
#include <vector>
#include <exception>
#include <stdexcept>
#include <iostream>

class CircularBuffer {
 public:
    explicit CircularBuffer(int capacity);

    void prettyPrint();

    // assignment
    bool isEmpty();
    bool isFull();
    void enqueue(int16_t x);
    int16_t dequeue();
    int16_t peek();
    int size();


 private:
        int len;
        int capacity;
        int head;
        int tail;
        int *buffer;
};
#endif  // CIRCULARBUFFER_H_
