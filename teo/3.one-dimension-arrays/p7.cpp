/*
    Example 7.
    Given two numbers in base 16 (m, n digits), perform the addition of both numbers.
    Do not convert to base 10.
*/

#include <iostream>

int max(int x, int y) {
    return (x > y) ? x : y;
}

int main() {

    int c1, c2;

    std::cin >> c1;

    char num1_h[c1];
    for (int i = 0; i < c1; i++) {
        std::cin >> num1_h[i];
    }

    std::cin >> c2;

    char num2_h[c2];
    for (int i = 0; i < c2; i++) {
        std::cin >> num2_h[i];
    }

    // perform sum

    int carry = 0, d1 = c1 - 1, d2 = c2 - 1, cs = max(c1, c2) + 1, ds = cs - 1;
    char sum_h[cs];

    while (ds >= 0) {
        
        int digit = carry;
        
        if (d1 >= 0) {
            if ('A' <= num1_h[d1] <= 'F') {
                digit += num1_h[d1] - 'A' + 10;
            }
            else {
                digit += num1_h[d1] - '0';
            }
        }
        
        if (d2 >= 0) {
            if ('A' <= num2_h[d2] <= 'F') {
                digit += num2_h[d2] - 'A' + 10;
            }
            else {
                digit += num2_h[d2] - '0';
            }
        }

        carry = digit / 16;
        digit = digit % 16;

        const char HEX_DIGITS[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
        char digit_h = HEX_DIGITS[digit];

        // switch (digit) {
        //     case 0:     digit_h = '0';  break;
        //     case 1:     digit_h = '1';  break;
        //     case 2:     digit_h = '2';  break;
        //     case 3:     digit_h = '3';  break;
        //     case 4:     digit_h = '4';  break;
        //     case 5:     digit_h = '5';  break;
        //     case 6:     digit_h = '6';  break;
        //     case 7:     digit_h = '7';  break;
        //     case 8:     digit_h = '8';  break;
        //     case 9:     digit_h = '9';  break;
        //     case 10:    digit_h = 'A';  break; 
        //     case 11:    digit_h = 'B';  break; 
        //     case 12:    digit_h = 'C';  break; 
        //     case 13:    digit_h = 'D';  break; 
        //     case 14:    digit_h = 'E';  break; 
        //     case 15:    digit_h = 'F';  break; 

        //     default: throw std::runtime_error("could not resolve hex sum. could it be a cosmic ray?");
        // }

        sum_h[ds] = digit_h;

        d1--; d2--; ds--;
    }

    std::cout << "sum: ";
    
    int i = 0;
    if (sum_h[0] == '0') {
        i++;
    }

    for (i; i < cs; i++) {
        std::cout << sum_h[i];
    }
    
    std::cout << std::endl;
 
    return 0;
}
