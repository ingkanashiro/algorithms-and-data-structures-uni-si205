// For some reason, this only works when compiled through the terminal (?)

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
    std::fstream file;

    file.open("planilla.dat", std::ios::in | std::ios::out);
    if (!file) {
        std::cout << "we had an oopsie whoopsie" << std::endl;
        throw std::runtime_error("couldn't open file planilla.dat");
    }

    file.seekg(0, file.end);
    int n = file.tellg() / sizeof(e);
    file.seekg(0, file.beg);

    for (int i = 0; i < n; i++) {
        file.read((char*)&e, sizeof(e));

        if (e.payroll > 2000) {
            e.payroll *= 0.9;
            
            file.seekp(i*sizeof(e));
            file.write((char*)&e, sizeof(e));
        }
    }

    file.close();
    std::cout << "file modified successfully!" << std::endl;

    return 0;
}