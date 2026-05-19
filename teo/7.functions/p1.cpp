#include <iostream>

double max(double x, double y) {
    if (x > y) {
        return x;
    }
    else {
        return y;
    }
}

int main() {

    double a, b, c, d, val;
    std::cin >> a >> b >> c >> d;

    val = max(a, max(b, max(c, d)));
    std::cout << "max: " << val;

    return 0;
}