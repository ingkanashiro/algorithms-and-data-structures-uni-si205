#include <iostream>

double max(double x[], int n) {
    if (n > 0) {
        if (x[n-1] > x[n-2]) {
            x[n-2] = x[n-1];
        }

        return max(x, n-1);
    }
    else {
        return x[0];
    }
}

int main() {

    int n;
    do { std::cin >> n; } while (n < 0);

    double a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    double max_a = max(a, n);
    std::cout << "max: " << max_a;

    return 0;
}