/*
    Example 3.
    Compute the sum of two 3-dimensional vectors.
*/

#include <iostream>

struct Vector2 {
    double x, y, z;
};

int main() {

    Vector2 v1, v2;

    std::cout << "v1 = ";
    std::cin >> v1.x >> v1.y >> v1.z;

    std::cout << "v2 = ";
    std::cin >> v2.x >> v2.y >> v2.z;

    // sum vectors
    Vector2 sumVec;
    sumVec.x = v1.x + v2.x;
    sumVec.y = v1.y + v2.y;
    sumVec.z = v1.z + v2.z;

    std::cout << "v1 + v2 = (" << sumVec.x << ", " << sumVec.y << ", " << sumVec.z << ")" << std::endl;
 
    return 0;
}