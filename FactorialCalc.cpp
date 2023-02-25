// A simple program that computes the factorial of a number
#include <cmath>
#include <iostream>
#include <string>

#include "DummyMathFunctions.h"

int main(int argc, char* argv[]) {
    std::cout << argv[0] << std::endl;
    std::cout << "Enter a number: ";

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    const uint32_t inputValue = std::stoul(argv[1]);

    const uint32_t outputValue = factorial(inputValue);

    std::cout << std::endl
              << "The factorial of " << inputValue << " is " << outputValue
              << std::endl;

    return 0;
}
