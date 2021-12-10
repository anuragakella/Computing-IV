/*
 * Copyright 2021 Anurag Akella
 * All rights reserved.
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

#include "CircularBuffer.h"

BOOST_AUTO_TEST_CASE(constructor) {
    // testing errors
    BOOST_REQUIRE_THROW(CircularBuffer(0), std::exception);
    BOOST_REQUIRE_THROW(CircularBuffer(0), std::invalid_argument);
    BOOST_REQUIRE_THROW(CircularBuffer(-1), std::invalid_argument);

    // testing normal
    BOOST_REQUIRE_NO_THROW(CircularBuffer(20));
}

BOOST_AUTO_TEST_CASE(size) {
    // some buffer
    CircularBuffer testBuffer(10);

    // testing errors
    BOOST_REQUIRE(testBuffer.size() == 0);

    testBuffer.enqueue(5);
    testBuffer.enqueue(5);

    BOOST_REQUIRE(testBuffer.size() == 2);

    testBuffer.dequeue();
    BOOST_REQUIRE(testBuffer.size() == 1);

    testBuffer.dequeue();
    BOOST_REQUIRE(testBuffer.size() == 0);

    testBuffer.enqueue(5);
    testBuffer.dequeue();
    BOOST_REQUIRE(testBuffer.size() == 0);
}

BOOST_AUTO_TEST_CASE(isEmpty) {
    CircularBuffer testBuffer(5);
    BOOST_REQUIRE(testBuffer.isEmpty() == true);

    testBuffer.enqueue(5);
    BOOST_REQUIRE(testBuffer.isEmpty() == false);
}

BOOST_AUTO_TEST_CASE(isFull) {
    CircularBuffer testBuffer(1);
    BOOST_REQUIRE(testBuffer.isFull() == false);

    testBuffer.enqueue(5);
    BOOST_REQUIRE(testBuffer.isFull() == true);
}

// testing enqueue
BOOST_AUTO_TEST_CASE(Enqueue) {
    // These test basic enqueuing
    CircularBuffer testBuffer(1);

    BOOST_REQUIRE_NO_THROW(testBuffer.enqueue(1));
    BOOST_REQUIRE(testBuffer.dequeue() == 1);

    testBuffer.enqueue(1);
    BOOST_REQUIRE_THROW(testBuffer.enqueue(1), std::runtime_error);
}

// testing dequeue
BOOST_AUTO_TEST_CASE(Dequeue) {
    CircularBuffer testBuffer(5);

    testBuffer.enqueue(0);
    testBuffer.enqueue(1);
    testBuffer.enqueue(2);

    BOOST_REQUIRE(testBuffer.dequeue() == 0);
    BOOST_REQUIRE(testBuffer.dequeue() == 1);
    BOOST_REQUIRE(testBuffer.dequeue() == 2);
    BOOST_REQUIRE_THROW(testBuffer.dequeue(), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(peek) {
    CircularBuffer testBuffer(1);

    BOOST_REQUIRE_THROW(testBuffer.peek(), std::runtime_error);

    testBuffer.enqueue(1);
    BOOST_REQUIRE(testBuffer.peek() == 1);
}
