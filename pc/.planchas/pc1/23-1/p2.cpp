#include <iostream>

int main() {

    int num;
    std::cin >> num;

    
    int prev = -1;
    while (num) {

        int digit = (num % 10);

        if (prev == (digit % 2)) {

            std::cout << "The number doesn't alternate" << std::endl;
            return 0;
        }
        
        prev = digit % 2;
        num /= 10;
    }

    std::cout << "The number alternates" << std::endl;
    

    return 0;
}