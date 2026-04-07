/*
    Problem 2.
    Input two integers M, N, each with 5 digits.
    Generate a new 5 digit number whose odd position digits are the corresponding digits of M and the even position digits are the corresponding digits of N.
    Determine, then, if the new number, labeled P, is a palindrome.
*/

#include <iostream>

using namespace std;

int main() {

    int M, N;
    cin >> M >> N;

    int pow10 = 100000;
    int result = 0;

    for (int i = 0; i < 5; i++) {
        
        int d = 0;
        if (i % 2 == 0) {
            d = ((M % pow10) - (M % (pow10 / 10))) / (pow10 / 10);
        }
        else {
            d = ((N % pow10) - (N % (pow10 / 10))) / (pow10 / 10);
        }

        result *= 10;
        result += d;

        pow10 /= 10;
    }

    cout << "P = " << result << endl;

    int resultInv = 0;
    pow10 = 10;

    for (int i = 0; i < 5; i++) {
        int d = ((result % pow10) - (result % (pow10 / 10))) / (pow10 / 10);

        resultInv *= 10;
        resultInv += d;

        pow10 *= 10;
    }

    if (result == resultInv) {
        cout << "P sí es capicúa" << endl;
    }
    else {
        cout << "P no es capicúa" << endl;
    }

    return 0;
}