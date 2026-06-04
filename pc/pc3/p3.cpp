#include <iostream>

bool sorted(int x[], int n) {

    for (int i = 0; i < n-1; i++) {
        if (x[i] >= x[i+1]) {
            return false;
        }
    }

    return true;
}

int digitsum(int x) {

    int sum = 0;
    while (x) {
        sum += x%10;
        x /= 10;
    }

    return sum;
}

int getfirstmds(int x[], int n) {
    int max = x[0];
    for (int i = 1; i < n; i++) {
        if (digitsum(x[i]) > digitsum(max)) {
            max = x[i];
        }
    }

    return max;
}

int main() {

    int n;
    std::cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    if (sorted(a, n)) {
        std::cout << "El arreglo está estrictamente ordenado en forma ascendente." << std::endl;
    }
    else {
        std::cout << "El arreglo NO está estrictamente ordenado en forma ascendente." << std::endl;
    }

    int max = getfirstmds(a, n);
    std::cout << "El primer elemento con la mayor suma de cifras es " << max << std::endl;

    return 0;
}