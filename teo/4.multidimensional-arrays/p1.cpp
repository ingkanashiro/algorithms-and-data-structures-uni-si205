/*
    We wish to store the final means of all students of sections U, V, W of the algorithms class, knowing there's up to 40 students in each section.
    Then, drop the means lower than 6.
*/

#include <iostream>

int main() {

    int n[3];
    for (int k = 0; k < 3; k++) {
        do {
            std::cin >> n[k];
        } while (n[k] > 40 || n[k] < 0);
    };

    double means[3][40];
    for (int k = 0; k < 3; k++) {
        
        for (int i = 0; i < n[k]; i++) {
            std::cin >> means[k][i];
        }
    }
    
    // Eliminate values lower than 6
    int len[3] = {n[0], n[1], n[2]};

    for (int k = 0; k < 3; k++) for (int i = 0; i < n[k]; i++) {

        if (i >= len[k]) break;

        if (means[k][i] < 6) {
            for (int j = i; j < n[k]; j++) {
                means[k][j] = means[k][j+1];
            }

            len[k]--; i--;
        }
    }

    // Print
    std::cout << std::endl;
    for (int k = 0; k < 3; k++) {

        char section = 'U' + k;
        std::cout << section << ": ";

        for (int i = 0; i < len[k]; i++) {
            std::cout << means[k][i] << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}