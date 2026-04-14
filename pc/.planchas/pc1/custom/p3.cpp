#include <iostream>

int main() {

    int n;
    std::cin >> n;

    int list[n];
    int inv_list[n];
    int result[n];

    for (int i = 0; i < n; i++) {
        std::cin >> list[i];
        inv_list[i] = 0;
        result[i] = 0;
    }

    for (int i = 0; i < n; i++) {

        int num = list[i];

        while (num) {

            int digit = (num % 10);
            bool isInAllNum = true;
            for (int j = 0; j < n; j++) {

                if (j == i) continue;

                int aux = list[j];

                bool hasDigit = false;
                while (aux) {
                    
                    if ((aux % 10) == digit) {
                        hasDigit = true;
                        break;
                    }
                    
                    aux /= 10;
                }

                if (!hasDigit) {
                    isInAllNum = false;
                    break;
                }
            }

            if (!isInAllNum) {
                inv_list[i] *= 10;
                inv_list[i] += digit;
            }

            num /= 10;
        }
    }

    for (int i = 0; i < n; i++) {
        while (inv_list[i]) {
            result[i] *= 10;
            result[i] += (inv_list[i] % 10);
            
            inv_list[i] /= 10;
        }
    }

    // Done! Yay!
    std::cout << "*** RESULTS ***" << std::endl;
    for (int r : result) {
        std::cout << r << " ";
    }

    return 0;
}