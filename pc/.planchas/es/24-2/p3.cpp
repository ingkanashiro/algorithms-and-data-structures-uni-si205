#include <iostream>
#include <fstream>

int getorder() {
    std::ifstream file;
    file.open("matriz.txt");

    if (!file) {
        throw std::runtime_error("couldn't open the file 'matriz.txt'.");
    }

    int k = 0, i;
    while (!file.eof()) {
        if (file >> i) {
            k++;
        }
    }

    int order = -1;
    for (int j = 5; j < k; j++) {
        if (j*j == k) {
            order = j;
            break;
        }
    }

    if (order == -1) {
        throw std::runtime_error("matriz is not valid.");
    }

    return order;
}

bool isprime(int x) {

    if (x < 2) {
        return false;
    }

    for (int i = 2; i < x; i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

int digitsum(int x) {

    int sum = 0;
    while (x) {

        sum += (x % 10);
        x /= 10;
    }

    return sum;
}

int main() {

    int n = getorder();
    int matrix[n][n];

    std::ifstream file;
    file.open("matriz.txt");

    if (!file) {
        throw std::runtime_error("couldn't open the file 'matriz.txt'.");
    }

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        file >> matrix[i][j];
    }

    file.close();

    int totalsum = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {

        int ii, jj;
        if (i < 2) { ii = 2 - i; } else { ii = i - 2; }
        if (j < 2) { jj = 2 - j; } else { jj = j - 2; }

        if (ii + jj <= (n/2) && !isprime(matrix[i][j])) {
            totalsum += digitsum(matrix[i][j]);
        }
    }

    std::cout << "sum: " << totalsum << std::endl;
    return 0;
}

