#include <iostream>

int main() {

    int m, n;
    std::cin >> m >> n;

    int A[m], B[n];

    for (int i = 0; i < m; i++) {
        do { std::cin >> A[i]; } while (A[i] < 0);
    }

    for (int i = 0; i < n; i++) {
        do { std::cin >> B[i]; } while (B[i] < 0);
    }

    int C[m+n];

    // Insertion sort
    
    int k = 0;
    for (int i = 0; i < m; i++) {
        
        int num = A[i];

        if (i == 0) {
            C[k] = num;
            k++; continue;
        }

        int j = 0;
        while (j < k) {

            if (num < C[j]) {

                for (int r = k; r > j; r--) {
                    C[r] = C[r-1];
                }

                C[j] = num;
                break;
            }

            if (++j == k) {
                C[j] = num;
            }
        }

        k++;
    }

    for (int i = 0; i < n; i++) {
        int num = B[i];

        bool isInA = false;
        for (int a : A) {
            if (a == num) {
                isInA = true;
                break;
            }
        }

        if (isInA) {
            continue;
        }

        int j = 0;
        while (j < k) {

            if (num < C[j]) {

                for (int r = k; r > j; r--) {
                    C[r] = C[r-1];
                }

                C[j] = num;
                break;
            }

            if (++j == k) {
                C[j] = num;
            }
        }

        k++;
    }

    std::cout << "C = {";
    for (int i = 0; i < k; i++) {
        std::cout << C[i] << (i == k-1 ? "}" : ", ");
    }

    return 0;
}