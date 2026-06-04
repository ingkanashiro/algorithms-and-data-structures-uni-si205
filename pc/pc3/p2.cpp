#include <iostream>

double tempadv(double T, int n) {
    if (n == 0) {
        return T;
    }

    return tempadv(T + 0.3*(T-70), --n);
}

int main() {

    int n;
    std::cin >> n;

    double temp = 110; // starting temp
    double newTemp = tempadv(temp, n);

    std::cout << "T = " << newTemp << "°F";
    return 0;
}