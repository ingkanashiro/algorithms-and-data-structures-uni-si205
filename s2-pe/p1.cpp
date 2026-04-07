/*
    Problem 1.
    Input a 3-digit integer and then insert between digits spaced by two the missing digit, so, for example, having the numbers 247,
    we return 2347.

    The use of arrays, string and non-standart functions is forbidden.
*/

#include <iostream>

using namespace std;

int main() {

    int num;
    cin >> num;

    int len = 0, temp = num;

    while (temp > 0) {
        len++;
        temp /= 10;
    }

    // abcd

    int pow10 = 1;

    for (int i = 0; i < len; i++) {
        pow10 *= 10;
    }

    bool insertedDigits = false;
    int result = 0, prev = -99;
    for (int i = 0; i < len; i++) {

        int d = ((num % pow10) - (num % (pow10 / 10))) / (pow10 / 10);

        if (d - prev == 2) {

            // we need to insert the mid number.

            result *= 10;
            result += d - 1;

            insertedDigits = true;
        }

        result *= 10;
        result += d;

        prev = d;
        pow10 /= 10;
    }

    if (insertedDigits) {
        cout << result << endl;
    }
    else {
        cout << "No hay digitos a insertar" << endl;
    }
    return 0;
}