#include <iostream>
#include <fstream>
#include <cstring>

typedef char string[32];

struct employee {
    int code;
    string name;
    float payroll;
};

int main() {

    int n;
    employee e;
    do { std::cin >> n; } while (n < 1);

    std::ofstream out;
    out.open("planilla.dat");

    if (!out) {
        throw std::runtime_error("could not create file planilla.dat");
    }

    for (int i = 0; i < n; i++) {
        std::cout << std::endl;

        std::cin >> e.code;
        fflush(stdin); gets(e.name); 
        std::cin >> e.payroll;

        out.write((char*)&e, sizeof(e));
    }

    out.close();
    std::cout << "data exported successfully!" << std::endl;

    return 0;
}