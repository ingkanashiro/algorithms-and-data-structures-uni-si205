#include <iostream>
#include <random>

void transpose(int **matrix, int **&dest, int order, int i, int j) {
    
    if (i >= order) return;
    
    if (j >= order) {
        transpose(matrix, dest, order, i+1, 0);
        return;
    }

    dest[i][j] = matrix[j][i];
    transpose(matrix, dest, order, i, j+1);
}

void gen(int **&matrix, int order) {
    for (int i = 0; i < order; i++) for (int j = 0; j < order; j++) {
        matrix[i][j] = (rand() % 50) + 1;
    }
}

int main() {
    srand(time(NULL));

    int n;
    do { std::cin >> n; } while (n < 4);

    int **matrix = new int*[n], **transposed = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        transposed[i] = new int[n];
    }

    gen(matrix, n);
    transpose(matrix, transposed, n, 0, 0);

    std::cout << "A:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "\t" << matrix[i][j];
        }
        std::cout << std::endl;
    }
    
    std::cout << std::endl;

    std::cout << "A^T:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "\t" << transposed[i][j];
        }
        std::cout << std::endl;
    }

    // clean the mess
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
        delete[] transposed[i];
    }

    delete[] matrix;
    delete[] transposed;

    return 0;
}