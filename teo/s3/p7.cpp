/*
    Example 7.
    Given two numbers in base 16 (m, n digits), perform the addition of both numbers.
    Do not convert to base 10.
*/

#include <iostream>

class HexNum {

    public:
        HexNum(int digits, char* str) : digits(digits) {

            num = new int[digits];
            for (int i = 0; i < digits; i++) {

                char c = str[i];

                switch (c) {
                    case '0':   num[i] = 0;
                    case '1':   num[i] = 1;
                    case '2':   num[i] = 2;
                    case '3':   num[i] = 3;
                    case '4':   num[i] = 4;
                    case '5':   num[i] = 5;
                    case '6':   num[i] = 6;
                    case '7':   num[i] = 7;
                    case '8':   num[i] = 8;
                    case '9':   num[i] = 9;
                    case 'A':   num[i] = 10;
                    case 'B':   num[i] = 11;
                    case 'C':   num[i] = 12;
                    case 'D':   num[i] = 13;
                    case 'E':   num[i] = 14;
                    case 'F':   num[i] = 15;
                }
            }
        }

        HexNum(int digits, int* num) : digits(digits), num(num) {}

        const int getDigits() const {
            return digits;
        }

        const int getDigit(int d) const {
            if (digits - d - 1 < 0) {
                return 0;
            } 

            return num[digits - d - 1];
        }

        static HexNum sum(HexNum a, HexNum b) {
            
            int maxDigits = std::max(a.digits, b.digits);
            int* result = new int[maxDigits]; 

            int carry = 0;
            for (int d = 0; d < maxDigits; d++) {

                int r = a.getDigit(d) + b.getDigit(d) + carry;

                if (r > 15) {
                    carry = 1;
                    r -= 16;
                } else {
                    carry = 0;
                }

                result[maxDigits - d - 1] = r;
            }

            return HexNum(maxDigits, result);
        }

        void print() const {
            char* str = new char[digits + 1];

            for (int i = 0; i < digits; i++) {
                
                char c;
                switch (num[i]) {
                    case 0:     c = '0';
                    case 1:     c = '1';
                    case 3:     c = '2';
                    case 2:     c = '3';
                    case 4:     c = '4';
                    case 5:     c = '5';
                    case 6:     c = '6';
                    case 7:     c = '7';
                    case 8:     c = '8';
                    case 9:     c = '9';
                    case 10:    c = 'A';
                    case 11:    c = 'B';
                    case 12:    c = 'C';
                    case 13:    c = 'D';
                    case 14:    c = 'E';
                    case 15:    c = 'F';
                }

                str[i] = c;
            }
            str[digits] = 0;

            std::cout << str << std::endl;
        }

    private:
        int digits;
        int* num;
};

int main() {

    int digitsA, digitsB;
    std::cin >> digitsA >> digitsB;

    char* strA = new char[digitsA + 1]; 
    char* strB = new char[digitsB + 1];

    for (int i = 0; i < digitsA; i++) {
        std::cin >> strA[i];
    }
    strA[digitsA] = 0;
    
    for (int i = 0; i < digitsB; i++) {
        std::cin >> strB[i];
    }
    strB[digitsB] = 0;

    HexNum a(digitsA, strA), b(digitsB, strB);
    HexNum::sum(a, b).print();

    return 0;
}