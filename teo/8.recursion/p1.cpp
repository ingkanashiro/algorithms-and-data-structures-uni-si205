#include <iostream>

long long int factorial(long long int x) {
    if (x == 0 || x == 1) {
        return 1;
    }

    return (x * factorial(x-1));
}

int main() {

    long long int in;
    do { std::cin >> in; } while (in < 0);

    long long int f = factorial(in);
    std::cout << in << "! = " << f << std::endl; 

    return 0;
}