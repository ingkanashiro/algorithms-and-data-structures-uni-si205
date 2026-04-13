#include <iostream>

int main() {

    int n;
    std::cin >> n;

    int positions[n];
    int leftMostPos, rightMostPos;

    bool areExtremesSet = false;

    for (int i = 0; i < n; i++) {

        std::cin >> positions[i];

        if (!areExtremesSet) {
            leftMostPos = positions[i];
            rightMostPos = positions[i];
        
            areExtremesSet = true;
            continue;
        }

        if (positions[i] < leftMostPos) {
            leftMostPos = positions[i];
        }

        if (positions[i] > rightMostPos) {
            rightMostPos = positions[i];
        }
    }

    // Test for all possible positions between the two extremes.

    int optimalPoint = leftMostPos;
    int minDist = 0;

    for (int p : positions) {
        minDist += ((p > leftMostPos ? 1 : -1)) * (p - leftMostPos); // abs(p - x)
    }

    for (int x = leftMostPos; x <= rightMostPos; x++) {

        int dist = 0;

        for (int p : positions) {
            dist += ((p > x ? 1 : -1)) * (p - x); // abs(p - x)
        }

        if (dist < minDist) {
            minDist = dist;
            optimalPoint = x;
        }
    }

    std::cout << "opt: " << optimalPoint << std::endl;
    std::cout << "  d: " << minDist << std::endl;

    return 0;
}