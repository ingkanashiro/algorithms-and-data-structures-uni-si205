/*
    Example 1.
    Given N employees, we wish to store their code (3 digits), age and year (4 digits).
    Sort the employee list in descending order respect of the year, then ascending order respect of the age and then descending order respect of the code.

    Test case:

    Input:
        N = 6

        300 13 2005
        400 13 2005
        100 15 2010
        500 11 2008
        200 14 2010
        600 13 2016
    
    Output:
        600 13 2016
        200 14 2010
        100 15 2010
        500 11 2008
        400 13 2005
        300 13 2005

*/

#include <iostream>

int main() {

    int N;
    std::cin >> N;

    int codes[N], ages[N], years[N], index[N];

    for (int i = 0; i < N; i++) {
        std::cin >> codes[i] >> ages[i] >> years[i];

        if (i == 0) {
            index[i] = i;
        }

        // Insertion sort
        int j = 0;
        while (j < i) {  // 3 2 1 0

            int num_i = years[i]*100000 - ages[i]*100 + codes[i], num_j = years[index[j]]*100000 - ages[index[j]]*100 + codes[index[j]];

            if (num_i > num_j) {

                for (int r = i; r > j; r--) {
                    index[r]=index[r-1];
                }

                index[j] = i;
                break;
            }

            if (++j == i) {
                index[j] = i;
            }
        }
    }

    std::cout << "*** SORTED LIST ***" << std::endl;
    for (int i : index) {
        std::cout << codes[i] << " " << ages[i] << " " << years[i] << std::endl;
    }

    return 0;
}