#include <iostream>

int main() {

    int num;
    std::cin >> num;

    int t = num, numOfDigits = 0;
    while (t) {
        numOfDigits++;
        t /= 10;
    }

    if (numOfDigits <= 3 || numOfDigits > 8) {
        std::cout << "No hay suficientes cifras." << std::endl;
        return 0;
    }

    if (num <= 0) {
        std::cout << "Error. Número no positivo." << std::endl;
    }

    int l, r = 0;
    
    int repeat = (numOfDigits + 1) / 2;
    while (repeat--) {
        r *= 10;
        r += (num % 10);

        if (repeat || !(numOfDigits % 2 == 1)) {
            num /= 10;
        }
    }

    l = num;

    // go through every number and change accordingly
    int rsplit = 0, lsplit = 0;

    while (r) {

        int rd = (r % 10), ld = (l % 10);
        int maxDigit = rd;

        if (rd != ld) {
            maxDigit = (rd > ld ? rd : ld);
        }

        rsplit *= 10;
        rsplit += maxDigit;

        r /= 10;
        l /= 10;
    }

    // flip for the other half
    int aux = rsplit;
    while (aux) {

        lsplit *= 10;
        lsplit += (aux % 10);

        aux /= 10;
    }

    if (numOfDigits % 2 == 1) {
        lsplit /= 10;
    }

    int T = (numOfDigits + 1) / 2;
    while (T--) {
        lsplit *= 10;
    }

    int result = lsplit + rsplit;
    std::cout << result << std::endl;

    return 0;
}