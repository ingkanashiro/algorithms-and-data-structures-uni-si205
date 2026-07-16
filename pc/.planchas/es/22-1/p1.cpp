#include <iostream>

void rotate(int list[], int order, int repeat, int layer) {

    int matrix[order][order];
    
    // to matrix
    for (int i = 0; i < order; i++) for (int j = 0; j < order; j++) {
        matrix[i][j] = list[i*order + j];
    }

    // rotate
    int m = order / 2;
    int L = m - layer, U = m + layer;
    
    for (int r = 0; r < repeat; r++) {
        
        int result[order][order];

        for (int v = 0; v < U-L; v++) {
            int p = matrix[L][L+v];

            matrix[L][L+v] = matrix[U-v][L];
            matrix[U-v][L] = matrix[U][U-v];
            matrix[U][U-v] = matrix[L+v][U];
            matrix[L+v][U] = p;  
        }
    }

    // return
    for (int i = 0; i < order; i++) for (int j = 0; j < order; j++) {
        list[i*order + j] = matrix[i][j];
    }
}

int main() {

    int order, repeat, layer;
    do { std::cin >> order; }   while (order < 3 || order % 2 == 0);
    do { std::cin >> repeat; }  while (repeat != 1 && repeat != 2 && repeat != 3);
    do { std::cin >> layer; }   while (layer > ((order + 1) / 2) || layer < 1);

    int list[order * order];
    for (int i = 0; i < order * order; i++) {
        std::cin >> list[i];
    }

    int start[order][order];

    for (int i = 0; i < order; i++) for (int j = 0; j < order; j++) {
        start[i][j] = list[i*order + j];
    }

    // test case: 5 1 2 
    //            1 2 3 4 5 6 7 8 9 0 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24  

    // the matrix is sent and returned as a chain of int because we can't send matrices into functions :(
    rotate(list, order, repeat, layer);

    int matrix[order][order];

    for (int i = 0; i < order; i++) for (int j = 0; j < order; j++) {
        matrix[i][j] = list[i*order + j];
    }

    // print result
    std::cout << "A:" << std::endl;
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            std::cout << start[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    
    std::cout << std::endl;

    std::cout << "f(A):" << std::endl;
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}