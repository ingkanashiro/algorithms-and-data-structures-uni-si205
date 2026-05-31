#include <iostream>

void sort(int x[], int n) {
    for (int i = 0; i < n; i++) for (int j = 0; j < n-1; j++) {
        if (x[j] > x[j+1]) {
            int t = x[j];
            x[j] = x[j+1];
            x[j+1] = t;
        }
    }
}

double median(int x[], int n) {

    sort(x, n);

    if (n % 2) {
        return x[n/2];
    }
    else {
        return (x[n/2] + x[n/2 - 1]) / 2;
    }
}

int main() {

    int n;
    std::cin >> n;

    double medianAvg = 0;
    for (int i = 0; i < n; i++) {

        int len;
        std::cin >> len;

        int a[len];

        for (int j = 0; j < len; j++) {
            std::cin >> a[j];
        }

        double med = median(a, len);

        std::cout << "median: " << med << std::endl;
        medianAvg += med;
    }

    medianAvg /= n;

    std::cout << std::endl;
    std::cout << "avg: " << medianAvg;

    return 0;
}