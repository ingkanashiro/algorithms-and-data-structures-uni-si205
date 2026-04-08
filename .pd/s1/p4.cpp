#include <iostream>

using namespace std;

int main() {

    float pointA[2], pointB[2];
    float slope;

    cin >> pointA[0] >> pointA[1] >> pointB[0] >> pointB[1];

    slope = (pointA[1] - pointB[1]) / (pointA[0] - pointB[0]);

    cout << slope;

    return 0;
}