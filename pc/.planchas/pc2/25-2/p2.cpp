#include <iostream>
#include <ctime>

int main() {

    srand(time(NULL));

    int n;
    do { std::cin >> n; } while (n % 2 == 0);

    int matrix[n][n];

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        matrix[i][j] = (rand() % 100) + 1; // fill with random values
    }

    int L = n/4, U = 3*n/4, size = U - L + 1;
    int submatrix[size][size];

    double fibonacciFreq = 0;
    for (int i = 0; i < size; i++) for (int j = 0; j < size; j++) {
        submatrix[i][j] = matrix[i+L][j+L];
        
        // Check for fibonacci
        int a = 1, b = 1;

        while (b <= submatrix[i][j]) {

            if (b == submatrix[i][j]) {
                fibonacciFreq++;
                break;
            }

            // next fibonacci
            int p = a;
            a = b;
            b = a + p;
        }
    }
    
    fibonacciFreq /= (size * size);
    fibonacciFreq *= 100;

    std::cout << "%fib: " << fibonacciFreq << "%" << std::endl;
    
    return 0;
}