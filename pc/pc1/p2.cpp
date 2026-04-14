#include <iostream>

int main() {
    
    int x;
    std::cin >> x;

    int evenDigitNum = 0, sumOfDigitsOver5 = 0;
    int t = 0, i = 0;

    while (x) {

        if (i % 2 == 0) {
            t *= 10;
            t += (x % 10);
        }

        if ((x % 10) > 5) {
            sumOfDigitsOver5 += (x % 10);
        }

        x /= 10;
        i++;
    }

    // Flip number back
    while (t) {

        evenDigitNum *= 10;
        evenDigitNum += (t % 10);

        t /= 10;
    }

    if (evenDigitNum % sumOfDigitsOver5 == 0) {
        std::cout << evenDigitNum << " es múltiplo de " << sumOfDigitsOver5 << std::endl;
    } else {
        std::cout << evenDigitNum << " no es múltiplo de " << sumOfDigitsOver5 << std::endl;
    }

    return 0;
}