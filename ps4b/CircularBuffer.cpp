/*
 * Copyright 2021 Anurag Akella
 * All rights reserved.
 * MIT Licensed - see http://opensource.org/licenses/MIT for details.
 */
#include "CircularBuffer.h"

CircularBuffer::CircularBuffer(int cap) {
    if (cap < 1) {
        throw
            std::invalid_argument\
            ("CircularBuffer constructor: capacity must be greater than zero");
    }

    capacity = cap;
    buffer = new int16_t[capacity];

    // intialize queue
    head = 0;
    tail = 0;
    len = 0;
}

int CircularBuffer::size() {
    return len;
}

bool CircularBuffer::isEmpty() {
    auto x = [](int len) {
        return len == 0;
    };
    return x(len);
}

void CircularBuffer::empty() {
  head = 0;
  tail = 0;
  len = 0;
}

bool CircularBuffer::isFull() {
    return (len == capacity) ? true : false;
}

void CircularBuffer::enqueue(int16_t x) {
  if (isFull()) {
    throw
      std::runtime_error("enqueue: can't enqueue to a full ring");
  }

  if (tail >= capacity) {
    tail = 0;
  }

  buffer[tail] = x;

  tail++;
  len++;
}

int16_t CircularBuffer::dequeue() {
  if (isEmpty()) {
    throw
      std::runtime_error("dequeue: can't dequeue an empty ring");
  }

  int16_t first = buffer[head];
  buffer[head] = 0;

  head++;
  len--;

  // Check to see if we need to loop first back around to 0.
  if (head >= capacity) {
    head = 0;
  }

  return first;
}

int16_t CircularBuffer::peek() {
  if (isEmpty()) {
    throw
      std::runtime_error("peek: can't peek an empty ring");
  }
  return buffer[head];
}

void CircularBuffer::prettyPrint() {
  std::cout << "Buffer: capacity " << capacity << " ";
  std::cout << ", tail " << tail;
  std::cout << ", head " << head;
  std::cout << ", current length " << len << "\n";
  std::cout << "Buffer: ";

  int front = 0;
  int back = head;

  while (front < len) {
    if (back >= capacity) {
      back = 0;
    }

    std::cout << buffer[back] << " ";
    back++;
    front++;
  }
  std::cout << std::endl;
}





