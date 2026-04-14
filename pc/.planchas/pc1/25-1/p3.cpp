#include <iostream>

int main() {

    int point1, point2;
    std::cin >> point1 >> point2;

    int x1, y1, x2, y2;

    y1 = point1 % 10;
    y2 = point2 % 10;

    x1 = point1 / 10;
    x2 = point2 / 10;

    if (((x2 > x1) ? 1 : -1)*(x2 - x1) == 1 && ((y2 > y1) ? 1 : -1)*(y2 - y1) == 1) {
        std::cout << "The points are diagonally adjacent";
    }
    else {
        std::cout << "The points are not diagonally adjacent";
    }

    return 0;
}