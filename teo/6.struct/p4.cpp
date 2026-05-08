/*
    Example 4.
    Compute the product of two complex numbers
*/

#include <iostream>

struct Complex {
    double a, b;
    
    // a + bi;
    static void print(Complex z) {
        std::cout << z.a << (z.b < 0 ? " - " : " + ") << ((z.b < 0) ? -1*z.b : z.b) << "i";
    }
};

int main() {

    Complex z1, z2, z;
    std::cout << "z1 = "; std::cin >> z1.a >> z1.b;
    std::cout << "z2 = "; std::cin >> z2.a >> z2.b;

    // product
    // (a+bi)(c+di) = ac + adi + bci - bd
    z.a = (z1.a*z2.a - z1.b*z2.b);
    z.b = (z1.a*z2.b + z1.b*z2.a);

    std::cout << "z1 * z2 = "; Complex::print(z);

    return 0;
}