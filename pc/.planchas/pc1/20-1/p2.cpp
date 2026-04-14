#include <iostream>

int main() {

    int n;
    std::cin >> n;

    int a = (n / 1.41);     // a2 + b2 = c2

    for (int l = 1; l <= a; l++) {

        // check if triangle is rectangle.
        int ss = (n*n) - (l*l);
        
        int s = -1;
        for (int q = 1; q < ss; s++) {
            if (q*q == ss) {
                s = q;
                break;
            }
        }

        if (s > 0) {
            std::cout << "triangle: " << l << " " << s << " " << n << std::endl;
        }
    }

    return 0;
}