#include <iostream>

int main() {

    int n;
    do { std::cin >> n; } while (n < 1);

    int A[n][n], B[n][2];

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        do { std::cin >> A[i][j]; } while (A[i][j] > 9 || A[i][j] < 0);
    }

    // input:
    // 4
    // 5 5 2 2 1 3 3 3 4 4 4 4 9 2 9 9

    for (int i = 0; i < n; i++) {

        int counts[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        int prev = A[i][0], current = 1;
        for (int j = 1; j < n; j++) {

            if (A[i][j] == prev) {
                current++;

                if (j == n-1 && current > counts[prev]) {
                    counts[prev] = current;
                    current = 1;
                }
            }
            else {
                if (current > counts[prev]) {
                    counts[prev] = current;
                    current = 1;
                }
            }

            prev = A[i][j];
        }

        // find largest most frequent consecutive
        int val = 0, count;
        for (int d = 0; d < 10; d++) {
            if (counts[d] >= counts[val]) {
                val = d;
            }
        }

        B[i][0] = val; B[i][1] = counts[val];
    }

    std::cout << std::endl;
    
    std::cout << "A:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "  " << A[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << "B:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << "  " << B[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}