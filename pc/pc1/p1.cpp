#include <iostream>

int main() {    // No la pude entregar pipipi

    int a, b;
    std::cin >> a >> b;

    int result = 0;

    while (a) {

        int t = b;

        bool digitExists = false;
        while (t) {
            if ((t % 10) == (a % 10)) {
                digitExists = true;
                break;
            }
            t /= 10;
        }

        if (!digitExists) {
            result *= 10;
            result += (a % 10);
        }

        a /= 10;
    }

    int t = result;
    result = 0;

    while (t) {
        result *= 10;
        result += (t % 10);

        t /= 10;
    }

    std::cout << result << std::endl;


    return 0;
}