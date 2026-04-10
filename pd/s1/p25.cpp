#include <iostream>
#include <cmath>

using namespace std;

struct point2 {
    double x;
    double y;

    point2(double x, double y) : x(x), y(y) {}
};

struct triangle {
    point2 vertexA;
    point2 vertexB;
    point2 vertexC;

    explicit triangle(point2 vertexA, point2 vertexB, point2 vertexC) : vertexA(vertexA), vertexB(vertexB), vertexC(vertexC) {}
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
    
    if (!constructsTriangle(pointA, pointB, pointC)) {
        return 0;
    }

    double a = dist(pointB, pointC);
    double b = dist(pointA, pointC);
    double c = dist(pointA, pointB);

    double p = (a + b + c) / 2;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double area(triangle triangle) {
    return area(triangle.vertexA, triangle.vertexB, triangle.vertexC);
}

bool isPointInTriangle(point2 point, triangle T) {

    double areaSum = area(T.vertexA, T.vertexB, point) + area(T.vertexB, T.vertexC, point) + area(T.vertexA, T.vertexC, point);
    return (abs(area(T) - areaSum) < 1e-9);
}

int main() {

    double x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    point2 pointA = point2(x1, y1);
    point2 pointB = point2(x2, y2);
    point2 pointC = point2(x3, y3);
    point2 pointD = point2(x4, y4);

    if (!constructsTriangle(pointA, pointB, pointC)) {
        throw runtime_error("no such triangle exists.");
    }

    triangle trgABC = triangle(pointA, pointB, pointC);

    // if the point is inside the triangle, then the area if forms with any other two verteces is smaller.
    if (isPointInTriangle(pointD, trgABC)) {
        cout << "Point D (" << pointD.x << ", " << pointD.y << ") is inside triangle ABC." << endl;
    }
    else {
        cout << "Point D (" << pointD.x << ", " << pointD.y << ") is not inside triangle ABC." << endl;
    }

    return 0;
}