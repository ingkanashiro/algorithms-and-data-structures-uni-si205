#include <iostream>

int main() {

    int num;
    std::cin >> num;
    
    int newNum = 0;
    int invNum = 0;
    
    while (num) {
        invNum *= 10;
        invNum += (num % 10);
        num /= 10;
    }

    while (invNum) {
        if ((invNum % 10) % 2 != 0) {
            newNum *= 10;
            newNum += (invNum % 10);
        }

        invNum /= 10;
    }

    std::cout << newNum << std::endl;

    return 0;
}