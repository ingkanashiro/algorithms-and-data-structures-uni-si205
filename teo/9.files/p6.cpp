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

    employee e;
    std::ifstream in;
    in.open("planilla.dat");

    if (!in) {
        throw std::runtime_error("could not open planilla.dat");
    }

    while (!in.eof()) {
        if (in.read((char*)&e, sizeof(e))) {
            std::cout << e.code << "\t\t" << e.name << "\t\t" << e.payroll << std::endl;
        }
    }

    in.close();

    return 0;
}