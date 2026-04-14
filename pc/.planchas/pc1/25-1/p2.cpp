#include <iostream>

int main() {

    int a, b;
    std::cin >> a >> b;

    int result = 0; 

    for (int i = 9; i > 0; i -= 2) {

        bool isInA = false, isInB = false;
        int t_a = a, t_b = b;

        while (t_a) {

            if (t_a % 10 == i) {
                isInA = true;
                break;
            }

            t_a /= 10;
        }

        while (isInA && t_b) { // optimization

            if (t_b % 10 == i) {
                isInB = true;
                break;
            }

            t_b /= 10;
        }

        if (isInA && isInB) {

            result *= 10;
            result += i;

        }
    }

    if (!result) {
        std::cout << "No common odd digits" << std::endl;
    }
    else {
        std::cout << "r: " << result << std::endl;
    }

    return 0;
}