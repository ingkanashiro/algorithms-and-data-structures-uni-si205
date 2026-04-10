/*
    Example 5.
    Given a set of N real numbers, store and present them sorted in ascending order without actually sorting the
    set of numbers. Use insertion process.
*/

#include <iostream>

int main() {

    int N;
    std::cin >> N;

    double list[N];
    


    for (int i = 0; i < N; i++) { // {a, b, c, d, ..., z}
        // (i) keeps track of the number of data
        
        double data;
        std::cin >> data;

        if (i == 0) {
            list[i] = data;
            continue;
        }

        for (int j = 0; j <= i; j++) { // {a, b, c} , i = 2 
            
            if (data < list[j]) {

                // Shift everything from j by 1.
                for (int k = N - 1; k > j; k--) {
                    list[k] = list[k - 1];
                }

                list[j] = data;
                break;
            }

            if (j == i) { // Insert in last position
                list[j] = data;
            }
        }

    }

    std::cout << "*** SORTED LIST ***" << std::endl;
    for (int l : list) {
        std::cout << l << " ";
    }

    return 0;
}