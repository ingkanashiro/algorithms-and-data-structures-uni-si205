#include <iostream>

int choose(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }

    return choose(n-1, k) + choose(n-1, k-1);
}

int main() {

    int n, k;
    std::cin >> n >> k;

    std::cout << n << " choose " << k << " = " << choose(n, k);

    return 0;
}