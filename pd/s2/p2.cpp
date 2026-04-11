#include <iostream>

int main() {

    int num;
    std::cin >> num;
    
    int newNum = 0;

    while (num) {
        if ((num % 10) % 3 != 0) {
            newNum *= 10;
            newNum += (num % 10);
        }

        num /= 10;
    }

    std::cout << newNum << std::endl;
    std::cout << newNum << std::endl;

    return 0;
}