#include <stdint.h>

#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <iostream>

#include "DummyMathFunctions.h"

bool areDoublesNearlyEqual(double a, double b) {
    // Source:
    // https://github.com/federico-busato/Modern-CPP-Programming/blob/master/03.Basic_Concepts_II.pdf
    // (Slide 94)
    const double normal_min = std::numeric_limits<double>::min();
    const double relative_error = 0.01;  // 1% relative error

    if (!(std::isfinite(a) && std::isfinite(b)))  // a = ±∞, b = ±∞ and NaN
        return false;

    double diff = std::abs(a - b);
    // if "a" and "b" are near to zero, the relative error is less effective
    if (diff <= normal_min)  // or also: user_epsilon * normal_min
        return true;
    double abs_a = std::abs(a);
    double abs_b = std::abs(b);
    return (diff / std::max(abs_a, abs_b)) <= relative_error;
}

TEST_CASE("Factorials are computed", "[factorial]") {
    REQUIRE(factorial(1) == 1);
    REQUIRE(factorial(2) == 2);
    REQUIRE(factorial(3) == 6);
    REQUIRE(factorial(10) == 3'628'800);
}

TEST_CASE("Square roots are computed", "[square]") {
    REQUIRE(areDoublesNearlyEqual(mysqrt(0), 0));
    REQUIRE(areDoublesNearlyEqual(mysqrt(1), 1));
    REQUIRE(areDoublesNearlyEqual(mysqrt(2), std::sqrt(2)));
    REQUIRE(areDoublesNearlyEqual(mysqrt(3), std::sqrt(3)));
    REQUIRE(areDoublesNearlyEqual(mysqrt(4), 2));
    REQUIRE(areDoublesNearlyEqual(mysqrt(5), std::sqrt(5)));
    REQUIRE(areDoublesNearlyEqual(mysqrt(6), std::sqrt(6)));
}