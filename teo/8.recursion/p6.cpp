#include <iostream>

int predict(int year) {
    switch (year) {
        case 1990:
            return 500; break;
        case 1991:
            return 450; break;
        case 1992:
            return 650; break;

        default:
            return (predict(year-1) + predict(year-2) + predict(year-3)) / 3;
    }
}

int main() {
    int year;
    do { std::cin >> year; } while (year < 1990);

    std::cout << "Prediction for year " << year << ": " << predict(year);
    return 0;
}