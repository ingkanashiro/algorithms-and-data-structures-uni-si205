#include <iostream>

int main() {

    int a, b, c;
    std::cin >> a >> b >> c;

    // ax2 + bx + c = 0
    double x1, x2;

    double disc = (b*b - 4*a*c);
    
    double D = disc;

    if (disc < 0) {
        std::cout << "no real roots." << std::endl;
    }
    else if (disc == 0) {
        D = 0;
    }
    else {

        double y = 1;
    
        const double e = 0.000001;
    
        while (D - y > e) {
            D = (D + y) / 2;
            y = disc / D;
        }
    
        x1 = ((-1*b) + D)/(2*a);
        x2 = ((-1*b) - D)/(2*a);
    }


    std::cout << "x1: " << x1 << std::endl;
    std::cout << "x2: " << x2 << std::endl;


    return 0;
}