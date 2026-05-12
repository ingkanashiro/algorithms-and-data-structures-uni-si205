#include <iostream>
#include <cmath>

struct point2 {
    int x, y;
};

double pyth(point2 A, point2 B) {
    return sqrt((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y));
}

double heron(double x, double y, double z) {
    double p = (x+y+z)/2;
    return sqrt(p*(p-x)*(p-y)*(p-z));
}

int main() {

    point2 A, B, C, D;
    std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;

    double ab, ac, ad, bc, bd, cd;

    ab = pyth(A, B);
    ac = pyth(A, C);
    ad = pyth(A, D);
    bc = pyth(B, C);
    bd = pyth(B, D);
    cd = pyth(C, D);

    if (!(ab < ac + bc && ac < ab + bc && bc < ab + ac)) {
        throw std::runtime_error("triangle does not exist.");
    } 

    double areaTriangle, subABD, subACD, subBCD;

    areaTriangle = heron(ab, bc, ac);
    subABD = heron(ab, bd, ad);
    subACD = heron(ac, cd, ad);
    subBCD = heron(bc, cd, bd);

    if (abs(subABD + subACD + subBCD - areaTriangle) < 1e-9) {
        std::cout << "El punto (" << D.x << ", " << D.y << ") está dentro de ABC" << std::endl; 
    }
    else {
        std::cout << "El punto (" << D.x << ", " << D.y << ") no está dentro de ABC" << std::endl; 
    }

    return 0;
}