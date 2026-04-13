#include <iostream>

int main() {

    int n;
    std::cin >> n;

    int instances[31];

    for (int i = 0; i < 31; i++) {
        instances[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int age;
        do { std::cin >> age; } while (age > 50 || age < 20);
        instances[age - 20]++;
    }

    for (int i = 0; i < 31; i++) {
        std::cout << (i + 20) << "a: " << instances[i] << std::endl;
    }

    return 0;
}