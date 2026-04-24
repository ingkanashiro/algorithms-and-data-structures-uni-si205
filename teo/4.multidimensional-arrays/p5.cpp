/*
    Example 5.
    A company has 4 departments, and each of these has 3 areas with up to 10 employees.
    Store the payroll of every employee and then:

    a) Present, for every department and area, the data sorted in descending order.
    b) For every department and area, delete the payroll of the employees below average. 
*/

#include <iostream>
#include <random>

int main() {

    std::random_device rd;
    std::mt19937 g(rd());

    std::uniform_int_distribution<> dist(1000, 10000);

    const int DEPARTMENTS = 4, AREAS = 3;
    double payroll[DEPARTMENTS][AREAS][10];

    for (int i = 0; i < DEPARTMENTS; i++) for (int j = 0; j < AREAS; j++) for (int k = 0; k < 10; k++) {
        payroll[i][j][k] = -1;
    }

    int numOfEmployees[DEPARTMENTS][AREAS];

    for (int i = 0; i < DEPARTMENTS; i++) for (int j = 0; j < AREAS; j++) {
        do { std::cin >> numOfEmployees[i][j]; } while (numOfEmployees[i][j] <= 0);
    }

    for (int i = 0; i < DEPARTMENTS; i++) for (int j = 0; j < AREAS; j++) for (int k = 0; k < numOfEmployees[i][j]; k++) {
        int q;
        // do { std::cin >> q; } while (q <= 0);
        q = dist(g);

        if (k == 0) {
            payroll[i][j][k] = q;
        }

        // Insertion sort

        int l = 0;
        while (l < k) {

            if (q > payroll[i][j][l]) {

                for (int r = numOfEmployees[i][j]; r > l; r--) {
                    payroll[i][j][r] = payroll[i][j][r-1];
                }
                payroll[i][j][l] = q;
            }

            if (++l == k) {
                payroll[i][j][l] = q;
            }
        }
    }

    for (int i = 0; i < DEPARTMENTS; i++) for (int j = 0; j < AREAS; j++) {
        std::cout << std::endl << "A" << (i+1) << "::d" << (j+1) << " -> ";
        
        for (int k = 0; k < numOfEmployees[i][j]; k++) {
            std::cout << payroll[i][j][k] << " ";
        }
    }



    return 0;
}