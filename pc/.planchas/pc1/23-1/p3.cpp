#include <iostream>
#include <iomanip>

int main() {

    double pi = 0, tolerance;
    std::cin >> tolerance;

    for (int i = 0; 1 >= tolerance * (2*i + 1); i++) {
        pi += ((i % 2 == 0) ? 1 : -1) * (1.0/(2*i + 1));
    }
    pi *= 4;

    std::cout << std::fixed << std::setprecision(20); // otherwise it stops after 5 digits
    std::cout << "pi = " << pi << std::endl;

    return 0;
}