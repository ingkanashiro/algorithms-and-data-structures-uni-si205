/*
    Problem 3.
    Given three real numbers, determine if a triangle of such sides can exist.
    If it can, determine wether the triangle is scalene, isosceles or equilateral.
*/

#include <iostream>

using namespace std;

int main() {

    double a, b, c;
    cin >> a >> b >> c;

    bool isValidTriangle = ((a - b < c && c < a + b) && (a - c < b && b < a + c) && (b - c < a && a < b + c));

    if (isValidTriangle) {

        cout << "Sí forman un triángulo" << endl;

        int numOfEqSides = (a == b) + (b == c) + (a == c); // Returns 0 if scalene, 1 if isosceles and 3 if equilateral.

        switch (numOfEqSides) {
            case 0:
                cout << "Es escaleno" << endl;
                break;
            case 1:
                cout << "Es isósceles" << endl;
                break;
            case 3:
                cout << "Es equilátero" << endl;
                break;
        }
    }
    else {
        cout << "No forman un triangulo" << endl; 
    }
    
    return 0;
}