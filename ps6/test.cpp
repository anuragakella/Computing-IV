// Copyright 2021 Anurag Akella

#include "RandWriter.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(base_test) {
    int k = 2;
    std::string str = "gagggagaggcgagaaa";
    RandWriter rWriter(str, k);

    std::cout << "Testing with: " << std::endl;
    std::cout << rWriter << std::endl;

    std::string gen = rWriter.generate("cg", 10);
    BOOST_REQUIRE(gen.length() == 10);

    BOOST_REQUIRE(rWriter.freq("aa") == 2);
    BOOST_REQUIRE(rWriter.freq("ga", 'g') == 4);
    BOOST_REQUIRE(rWriter.freq("ag", 'a') == 3);
    BOOST_REQUIRE(rWriter.freq("ag", 'c') == 0);

    // a is the only character that comes after cg
    char rand = rWriter.k_Rand("cg");
    BOOST_REQUIRE(rand == 'a');

    BOOST_REQUIRE(rWriter.order_k() == k);
}

BOOST_AUTO_TEST_CASE(exception_test) {
    RandWriter rWriter("pqrs", 4);
    BOOST_REQUIRE_THROW(rWriter.freq("x"), std::runtime_error);
    BOOST_REQUIRE_THROW(rWriter.freq("bb", 'b'), std::runtime_error);
    BOOST_REQUIRE_THROW(rWriter.k_Rand("y"), std::runtime_error);
}
