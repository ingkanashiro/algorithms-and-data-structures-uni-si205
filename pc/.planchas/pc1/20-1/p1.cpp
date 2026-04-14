#include <iostream>

int to_base(int x, int b) {

    int sign = (x < 0) ? -1 : 1;
    x *= sign;

    int result = 0, d = 0;
    while (x) {

        int digit = (x % b);
        
        result *= 10;
        result += digit;

        x /= b;
    }

    return (sign * result);
}

int reverse(int x) {

    int sign = (x < 0) ? -1 : 1;
    x *= sign;

    int result = 0;
    while (x) {
        result += (x % 10);
        x /= 10;
    }

    return (sign * result);
}

int main() {

    int num;
    std::cin >> num;

    int num_2 = to_base(num, 2);
    int num_3 = to_base(num, 3);
    int num_4 = to_base(num, 4);
    int num_5 = to_base(num, 5);
    int num_6 = to_base(num, 6);
    int num_7 = to_base(num, 7);
    int num_8 = to_base(num, 8);
    int num_9 = to_base(num, 9);

    if (num_2 == reverse(num_2)) {
        std::cout << "The number is a palindrome in base 2" << std::endl;
    }

    if (num_3 == reverse(num_3)) {
        std::cout << "The number is a palindrome in base 3" << std::endl;
    }

    if (num_4 == reverse(num_4)) {
        std::cout << "The number is a palindrome in base 4" << std::endl;
    }

    if (num_5 == reverse(num_5)) {
        std::cout << "The number is a palindrome in base 5" << std::endl;
    }

    if (num_6 == reverse(num_6)) {
        std::cout << "The number is a palindrome in base 6" << std::endl;
    }

    if (num_7 == reverse(num_7)) {
        std::cout << "The number is a palindrome in base 7" << std::endl;
    }

    if (num_8 == reverse(num_8)) {
        std::cout << "The number is a palindrome in base 8" << std::endl;
    }

    if (num_9 == reverse(num_9)) {
        std::cout << "The number is a palindrome in base 9" << std::endl;
    }

    return 0;
}