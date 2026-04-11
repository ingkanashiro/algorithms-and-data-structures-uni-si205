#include <iostream>

int main() {

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {

        int i_temp = i;
        int cubeSum = 0;

        while (i_temp) {

            int d = (i_temp % 10);
            cubeSum += (d*d*d);

            i_temp /= 10;
        }

        if (i == cubeSum) {
            std::cout << i << " ";
        }
    }

    return 0;
}