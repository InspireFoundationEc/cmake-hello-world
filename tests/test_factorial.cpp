#include <stdint.h>

#include <cmath>
#include <iostream>

#include "DummyMathFunctions.h"
#include "doctest.h"

TEST_CASE("testing the factorial function") {
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
    CHECK(factorial(10) == 3628800);
}
