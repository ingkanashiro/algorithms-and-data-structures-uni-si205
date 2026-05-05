#include <iostream>
#include <ctime>

int main() {
    srand(time(NULL));

    int n;
    do { std::cin >> n; } while (n % 2);

    int matrix[n][n];

    // fill matrix with random values
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        matrix[i][j] = rand() % 100; // test values like example
    }

    // print matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << '\t';
        }

        std::cout << '\n';
    }

    // twist
    int twisted[n][n];

    for (int l = 0; l < n/2; l++) {

        // in every layer, we must go to a row and shift, then a column and shift, then a row, and then a column

        for (int v = l+1; v < n-l; v++) {

            int L = l, R = n-l-1;

            twisted[L][v] = matrix[L][v-1];     // top row
            twisted[v][R] = matrix[v-1][R];     // right column
            twisted[R][v-1] = matrix[R][v];     // bottom row
            twisted[v-1][L] = matrix[v][L];     // left column
        }
    }

    // print twisted
    std::cout << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << twisted[i][j] << '\t';
        }

        std::cout << '\n';
    }

    return 0;
}