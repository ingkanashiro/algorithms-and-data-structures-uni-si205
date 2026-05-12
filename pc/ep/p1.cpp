#include <iostream>

int main() {

    int num, numOfDigits = 0;
    do {
        std::cin >> num;
        numOfDigits = 0;
        int T = num;

        while (T) {
            T /= 10; numOfDigits++;
        }

    } while (numOfDigits < 4);

    int T = num;
    double avg = 0;

    while (T) {

        int d = T % 10;
        avg += d;

        T /= 10;
    }

    avg /= numOfDigits;

    // round avg
    int avg_i = avg, avg_r;

    if (avg - avg_i < 0.5) {
        avg_r = avg_i;
    }
    else {
        avg_r = avg_i + 1;
    }

    // std::cout << "dígito promedio: " << avg_r << std::endl;

    T = num;

    int mod_reversed = 0, mod = 0;
    while (T) {
        if ((T % 10) != avg_r) {
            mod_reversed *= 10;
            mod_reversed += (T % 10);
        }
        T /= 10;
    }

    while (mod_reversed) {
        mod *= 10;
        mod += (mod_reversed % 10);
        mod_reversed /= 10;
    }

    std::cout << std::endl;
    std::cout << "número original: " << num << std::endl;
    std::cout << "número modificado: " << mod << std::endl;

    return 0;
}