#include <iostream>

int fibonacci(int x) {
    if (x == 0 || x == 1) {
        return 1;
    }

    return fibonacci(x-1) + fibonacci(x-2);
}

int main() {
    int n;
    std::cout << "index: "; std::cin >> n;

    if (n < 0) throw std::runtime_error("could not resolve fibonacci for given input.");

    int f = fibonacci(n);
    std::cout << "F(" << n << ") = " << f << std::endl;
} 