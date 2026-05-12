#include <iostream>
#include <cstring>

typedef char string[64];

int main() {

    string strA = "15", strB = "25";
    int a, b;

    a = atoi(strA); // a = 15
    b = atoi(strB); // b = 25

    int r = a + b;  // r = 40

    std::cout << r << std::endl;

    return 0;
}