#include <iostream>

// A bad square root calculation using simple operations, just to show how to
// create a library
double mysqrt(double x) {
    if (x <= 0) {
        return 0;
    }

    double result = x;

    for (int i = 0; i < 10; ++i) {
        if (result <= 0) {
            result = 0.1;
        }
        double delta = x - (result * result);
        result = result + 0.5 * delta / result;
        std::cout << "approx. sqrt of " << x << " = " << result
                  << " (iteration #" << i + 1 << ")" << std::endl;
    }
    return result;
}