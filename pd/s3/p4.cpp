#include <iostream>

int main() {

    int n;
    std::cin >> n;

    int result[2*n]; // the maximum possible size of the array, given that all numbers are digit-odd.
    
    int i = 0; // i also keeps track of the size of the array.

    while (n--) {

        int num;
        std::cin >> num;

        int t = num;
        if (t < 0) { t *= -1; }
        
        bool allEven = ((t % 10) % 2 == 0), allOdd = ((t % 10) % 2 == 1);

        while (t) {

            if ((t % 10) % 2 != allOdd) {
                allOdd = false;
                allEven = false;
            }

            t /= 10;
        }
        
        if (allOdd) {
            result[i++] = num;
            result[i++] = num;
        }
        else if (!allEven) {
            result[i++] = num;
        }
    }

    std::cout << "*** MODIFIED ARRAY ***" << std::endl;
    for (int k = 0; k < i; k++) {
        std::cout << result[k] << " ";
    }

    return 0;
}