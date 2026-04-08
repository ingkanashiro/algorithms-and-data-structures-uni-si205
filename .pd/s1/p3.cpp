#include <iostream>
#include <cmath>

using namespace std;

struct point2 {
    double x;
    double y;

    point2(double x, double y) : x(x), y(y) {}
};

double dist(point2 pointA, point2 pointB) {
    return sqrt((pointB.y - pointA.y)*(pointB.y - pointA.y) + (pointB.x - pointA.x)*(pointB.x - pointA.x));
}

bool constructsTriangle(point2 pointA, point2 pointB, point2 pointC) {

    double a = dist(pointB, pointC);
    double b = dist(pointA, pointC);
    double c = dist(pointA, pointB);

    return (a < b + c && b < a + c && c < a + b);
}

double area(point2 pointA, point2 pointB, point2 pointC) {
    
    double a = dist(pointB, pointC);
    double b = dist(pointA, pointC);
    double c = dist(pointA, pointB);

    double p = (a + b + c) / 2;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    
    double x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    point2 pointA = point2(x1, y1);
    point2 pointB = point2(x2, y2);
    point2 pointC = point2(x3, y3);

    if (!constructsTriangle(pointA, pointB, pointC)) {
        throw runtime_error("no such triangle exists.");
    }

    double surfaceArea = area(pointA, pointB, pointC);
    cout << "S = " << surfaceArea << " sq-u" << endl;

    return 0;
}