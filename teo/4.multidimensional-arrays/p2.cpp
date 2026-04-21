/*
    We wish to store the final means of all students of sections U, V, W of the algorithms class, knowing there's up to 40 students in each section.
    Then, present the array sorted in descending order. The array must be filed in already sorted, which means, every new element of the array must be added to the correct
    sorted position.
*/

#include <iostream>

int main() {

    int n[3];
    for (int k = 0; k < 3; k++) {
        do {
            std::cin >> n[k];
        } while (n[k] > 40 || n[k] < 0);
    };

    // Insertion sort

    double means[3][40];
    for (int k = 0; k < 3; k++) for (int i = 0; i < n[k]; i++) {
        means[k][i] = 0;
    }

    for (int k = 0; k < 3; k++) for (int i = 0; i < n[k]; i++) { // 5 4 2 1 1 0 0 0
        
        int mean;
        std::cin >> mean;

        if (i == 0) {
            means[k][i] = mean;
            continue;
        }
        
        // Insert5 
        int j = 0;
        while (j < i) {

            if (mean > means[k][j]) {
                for (int r = i; r >= j; r--) {
                    means[k][r+1] = means[k][r];
                }

                means[k][j] = mean;
                break;
            }

            if (j++ == i) {
                means[k][j] = mean;
            }
            
        }

    }
    
    // Print
    std::cout << std::endl;
    for (int k = 0; k < 3; k++) {

        char section = 'U' + k;
        std::cout << section << ": ";

        for (int i = 0; i < n[k]; i++) {
            std::cout << means[k][i] << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}