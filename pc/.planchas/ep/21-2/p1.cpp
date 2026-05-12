#include <iostream>

int main() {

    int n;
    std::cin >> n;

    int ages[n];

    for (int i = 0; i < n; i++) {

        int age;
        std::cin >> age;

        if (i == 0) {
            ages[i] = age;
            continue;
        }

        int j = 0;
        while (j < i) {

            if (age > ages[j]) {
                for (int r = i; r > j; r--) {
                    ages[r] = ages[r-1];
                }
                ages[j] = age;

                break;
            }

            if (++j == i) {
                ages[j] = age;
            }
        }
    }


    int q = 0;
    while (q*q < n) {
        q++;
    }

    int matrix[q][q];

    /*
        # # # # *
        # # # # #
        # # # # #
        # # # # #
        # # # # #
    */

    int i = 0, j = 0, k = 0;
    int L = 0, R = q-1, U = 0, D = q-1;

    int v[2] = {0, 1};
    
    while (k < q*q) {

        if (k < n) {
            matrix[i][j] = ages[k];
        }
        else {
            matrix[i][j] = 0;
        }

        if ((j == R && v[0] == 0 && v[1] == 1) || (i == D && v[0] == 1 && v[1] == 0)
        || (j == L && v[0] == 0 && v[1] == -1) || (i == U && v[0] == -1 && v[1] == 0)) {

            if ((j == L && v[0] == 0 && v[1] == -1)) {
                L++; U++; R--; D--;
            }

            std::swap(v[0], v[1]);
            v[1] *= -1;
        }
        
        i += v[0]; j += v[1];

        k++;
    }


    // print
    std::cout << std::endl << "matrix:" << std::endl;

    for (int i = 0; i < q; i++) {
        for (int j = 0; j < q; j++) {
            std::cout << matrix[i][j] << '\t';
        }

        std::cout << '\n';
    }


    return 0;
}