#include <iostream>

float f(int k) {

    if (k == 0) {
        return 0;
    }
    else {
        return (2 * (3.14159265358979) * (1.5 + k*(0.005))) + f(k--);
    }
}

int main() {

    int k;
    std::cin >> k;

    std::cout << "len = " << f(k) << std::endl;
    return 0;
}