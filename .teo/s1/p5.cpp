/*
    Example 5.
    Given two numbers, find the greater number by only using switch()
*/

#include <iostream>

using namespace std;

int main() {

    float a, b, max;
    cin >> a >> b;

    switch (a > b) {
        case true:
            max = a;
            break;
        case false:
            max = b;
            break;
    }

    cout << max;
    
    return 0;
}