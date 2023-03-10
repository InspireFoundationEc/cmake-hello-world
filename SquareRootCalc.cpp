// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>

#include "DummyMathFunctions.h"

int main(int argc, char* argv[]) {
    // Print app name and prompt for input (number)
    std::cout << argv[0] << std::endl;
    std::cout << "Enter a number: ";

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    const double inputValue = std::stod(argv[1]);

    const double outputValue = mysqrt(inputValue);
    std::cout << std::endl
              << "The square root of " << inputValue << " is " << outputValue
              << std::endl;
    return 0;
}