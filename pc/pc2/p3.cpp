#include <iostream>
#include <ctime>

int main() {
    srand(time(NULL));

    int n;
    std::cin >> n;

    int chain[4*n];
    for (int i = 0; i < 4*n; i++) {
        chain[i] = rand() % 10;
    }

    // print chain
    std::cout << "c: ";
    for (int d : chain) {
        std::cout << d;
    }
    std::cout << std::endl;

    double avgDist[10];
    int numOfInstances[10];

    for (int i = 0; i < 10; i++) {
        
        numOfInstances[i] = 0;
        avgDist[i] = 0;
        
        int dist = 0;
        
        for (int k = 0; k < 4*n; k++) {
            dist++;

            if (chain[k] == i) {
                avgDist[i] += dist;
                dist = 0;
                numOfInstances[i]++;
            }
        }

        if (numOfInstances[i] > 0) {    // given the rare case where there are no instances of a digit, the average distance will be infinity.
            avgDist[i] /= numOfInstances[i];
        }
        else {
            avgDist[i] = -1;
        }
    }

    std::cout << std::endl << "dist:" << std::endl;
    for (int i = 0; i < 10; i++) {
        
        std::cout << "\t" << i << ": ";

        if (avgDist[i] == -1) {
            std::cout << "Infinity" << std::endl;
        }
        else {
            std::cout << avgDist[i] << std::endl;
        }
    }


    return 0;
}