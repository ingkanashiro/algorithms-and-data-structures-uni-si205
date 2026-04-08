/*
    Problem 2.
    Calculate the volume of a cube. You must ask for the side length.
*/

#include <iostream>

using namespace std;

int main() {
    
    double l;
    cin >> l;

    double vol = l * l * l;

    cout << "Cube of side " << l << " u has volume of " << vol << " u^3." << endl;
    return 0;
}