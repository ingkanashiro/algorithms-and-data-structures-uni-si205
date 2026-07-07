#include <iostream>

double x(int n) {
    
    if (n == 0) {
        return 0;
    }
    else {
        return (2 * 3.14159265358979 * (1.5 + ((n-1) * 0.005))) + x(n - 1);
    }
}

int main() {

    int n;
    do { std::cin >> n; } while (n < 0);

    std::cout << "len: " << x(n) << " cm" << std::endl;

    return 0;
}
