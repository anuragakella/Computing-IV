// Dr. Rykalova
// test.cpp for PS1a
// updated 1/31/2020

/*
*  Computing IV - Assignment - PS1a
*  Instructor: Prof. Yelena Rykalova
*
*  Due Date: 20th September 2021
*
*  Author: Anurag Akella (ID 01990503)
*
*  Description: This program is an implementation of a Fibonacci Linear Feedback Shift Register
                Takes in a seed and generates bits with seed() and numbers with generate(int)
                This is the test file with BOOST unit tests
*/

#include <iostream>
#include <string>

#include "FibLFSR.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);

  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(9) == 51);
}

// This test case uses a twenty bit seed to test the LFSR implementation
// more than 14 bits might be needed to run because this implementation has fixed tap values (given in the assignment problem)
BOOST_AUTO_TEST_CASE(TwentyBitsThreeTaps) {

  FibLFSR l("10101001101010011010");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);

  FibLFSR l2("10101001101010011010");
  BOOST_REQUIRE(l2.generate(5) == 14);
}

// This test case tests another seed that is 16 bits long
// just to make sure that other values work
BOOST_AUTO_TEST_CASE(SixteenBitsThreeTaps2) {
  FibLFSR l("1011011000110111");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);

  FibLFSR l2("1011011000110111");
  BOOST_REQUIRE(l2.generate(5) == 3);
}
