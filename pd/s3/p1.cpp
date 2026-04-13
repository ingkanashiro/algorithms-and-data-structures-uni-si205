#include <iostream>

int main() {

    int n;
    std::cin >> n;

    int codes[n], units[n];
    double prices[n], averageUnits = 0;

    for (int i = 0; i < n; i++) {
        std::cin >> codes[i] >> units[i] >> prices[i];
        averageUnits += units[i];
    }

    averageUnits /= n;

    // delete every product with lower-than-average units
    
    int newN = 0;
    for (int u : units) {
        if (u >= averageUnits) {
            newN++;
        }
    }

    int newCodes[newN], newUnits[newN];
    double newPrices[newN];

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (units[i] >= averageUnits) {

            newCodes[j] = codes[i];
            newUnits[j] = units[i];
            newPrices[j] = prices[i];

            j++;
        }
    }

    std::cout << "*** PURGED LIST ***" << std::endl;
    for (int i = 0; i < newN; i++) {
        std::cout << newCodes[i] << '\t' << newUnits[i] << '\t' << newPrices[i] << std::endl;
    }

    return 0;
}