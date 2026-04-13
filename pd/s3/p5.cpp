#include <iostream>

int main() {
    
    int n;
    std::cin >> n;

    int ages[n];

    // Insertion sort

    for (int i = 0; i < n; i++) {
        
        int age;
        std::cin >> age;

        if (i == 0) {
            ages[0] = age;
            continue;
        }

        int j = 0;
        while (j < i) {
            if (age < ages[j]) {

                // shift everything
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

    std::cout << "*** SORTED ARRAY ***" << std::endl;
    for (int a : ages) {
        std::cout << a << " ";
    }

    return 0;
}