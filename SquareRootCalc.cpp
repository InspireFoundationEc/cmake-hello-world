// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>

#include "SquareRootCalcConfig.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        // report version
        std::cout << argv[0] << " Version " << SquareRootCalc_VERSION_MAJOR
                  << "." << SquareRootCalc_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    const double inputValue = std::stod(argv[1]);

    const double outputValue = sqrt(inputValue);
    std::cout << "The square root of " << inputValue << " is " << outputValue
              << std::endl;
    return 0;
}