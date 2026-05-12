#include <iostream>

int main() {

    int n;
    std::cin >> n;

    int nums[n];
    int numOfDigits[n];

    int d = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];

        int num = nums[i];
        int k = 0;
        while (num) {
            k++;
            num /= 10;
        }

        d += k;
        numOfDigits[i] = k;
    }

    int digits[d];

    int l = 0;
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        
        for (int e = numOfDigits[i]-1; e >= 0; e--) {
            int exp = 1, T = e;
            while (T--) {
                exp *= 10;
            }

            int k = ((num % exp) - (num % (exp/10))) / (exp/10);
            digits[l] = k;

            l++;
        }
    }

    int VALUE = 7;
    for (int i = 0; i < d; i++) {
        std::cout << ((digits[i] == VALUE) ? " " : std::to_string(digits[i]));
    }

    return 0;
}