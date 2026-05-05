#include <iostream>

int main() {

    int n;
    do { std::cin >> n; } while (n > 200 || n <= 0);

    int codes[n];   // code in [100, 999] 
    double prices[n];

    for (int i = 0; i < n; i++) {
        do { std::cin >> codes[i]; } while (codes[i] > 999 || codes[i] < 100);
        do { std::cin >> prices[i]; } while (prices[i] < 0); 
    }

    // OUTPUT
    // codes | avg | numUnderAvg

    double avg[900];
    int numOfInstances[900], numUnderAvg[900];

    for (int i = 0; i < 900; i++) {
        numOfInstances[i] = 0;
        numUnderAvg[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        numOfInstances[codes[i]-100]++;
        avg[codes[i]-100] += prices[i];
    }

    for (int i = 0; i < 900; i++) {
        avg[i] /= numOfInstances[i];
    }

    for (int i = 0; i < n; i++) {
        if (prices[i] < avg[codes[i]-100]) {
            numUnderAvg[codes[i]-100]++;
        }
    }

    // Output
    for (int i = 0; i < 900; i++) {
        if (numOfInstances[i] > 0 && numUnderAvg[i] > 0) {
            std::cout << (i+100) << "\t" << avg[i] << "\t" << numUnderAvg[i] << std::endl; 
        }
    }

    return 0;
}