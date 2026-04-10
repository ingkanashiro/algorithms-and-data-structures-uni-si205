/*
    Problem 14.
    Given three integers, find the smallest and the number of instances of said number.
    Use only arithmetic operators.
*/

#include <iostream>

using namespace std;

int main() {

    int a, b, c;
    cin >> a >> b >> c;

    int m = ((b * (a / b)) + (a * (b / a))) / ((a / b) + (b / a));
    int min = ((m * (c / m)) + (c * (m / c))) / ((c / m) + (m / c));

    int numOfInstances = (m / a) + (m / b) + (m / c);

    cout << "min: " << min << endl;
    cout << "  i: " << numOfInstances << endl;

    return 0;
}