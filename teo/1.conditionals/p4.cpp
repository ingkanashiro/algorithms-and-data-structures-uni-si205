/*
    Example 4.
    Given four numbers, sort them in descending order.
    You're only allowed to use arithmetic operators and if()
*/

#include <iostream>

using namespace std;

void swap(float& x, float& y) {
    float aux = x;
    x = y;
    y = aux;
}

int main() {

    float a, b, c, d;
    cin >> a >> b >> c >> d;

    if (b > a) {
        swap(a, b);
    }

    if (d > c) {
        swap(d, c);
    }
    
    if (c > a) {
        swap(c, a);
    }

    if (d > b) {
        swap(d, b);
    }

    if (c > b) {
        swap(c, b);
    }

    cout << "Sorted: [" << a << ", " << b << ", " << c << ", " << d << "]";
    return 0;
}