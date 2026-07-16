#include <iostream>

// test case: 5 15 0 1 20 30 17 4 9 8 25 11 16 5 3 2 22 18 21 10 14 13 19 15 1 7 6 23 0

int main() {

    int n, T, h, k;

    do { std::cin >> n; } while (n < 2 || n % 2 == 0);
    do { std::cin >> T; } while (T < 1);
    do { std::cin >> h; } while (h != 0 && h != 1);
    do { std::cin >> k; } while (k != 1 && k != 2 && k != 3);

    int matrix[n][n];

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        std::cin >> matrix[i][j];
    }

    // a) Reduce from cap T.
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (matrix[i][j] > T) {
            matrix[i][j] = 0;
        }
    }

    // b) Apply vertical gravity
    for (int j = 0; j < n; j++) for (int r = 0; r < n; r++) for (int i = n-1; i > 0; i--) {
        if (matrix[i][j] == 0) {
            matrix[i][j] = matrix[i-1][j];
            matrix[i-1][j] = 0;
        }
    }

    // c) Rotate k times
    int U = n-1;
    if (h == 0) {
        for (int r = 0; r < k; r++) for (int v = 0; v < U; v++) {
            int x = matrix[0][v];
            
            matrix[0][v] = matrix[U-v][0];
            matrix[U-v][0] = matrix[U][U-v];
            matrix[U][U-v] = matrix[v][U];
            matrix[v][U] = x;
        }
    }
    else {
        for (int r = 0; r < k; r++) for (int v = 0; v < n; v++) {
            int x = matrix[v][U];

            matrix[U-v][0] = matrix[0][v];
            matrix[U][U-v] = matrix[U-v][0];
            matrix[v][U] = matrix[U-v][U];
            matrix[0][v] = x;
        }
    }

    // print
    std::cout << "A:" << std::endl;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "\t" << matrix[i][j]; 
        }
        std::cout << std::endl;
    }

    return 0;
}