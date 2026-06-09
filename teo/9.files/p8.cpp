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

    int n;

    std::fstream file;
    file.open("planilla.dat", std::ios::in | std::ios::out);

    file.seekg(0, file.end);
    n = file.tellg() / sizeof(employee);
    file.seekg(0, file.beg);
    
    employee e1, e2;

    for (int i = 0; i < n; i++) for (int j = 0; j < n-1; j++) {
        file.seekg(j*sizeof(employee));     file.read((char*)&e1, sizeof(employee));
        file.seekg((j+1)*sizeof(employee)); file.read((char*)&e2, sizeof(employee));

        if (e1.payroll > e2.payroll) {
            file.seekp(j*sizeof(employee));     file.write((char*)&e2, sizeof(employee));
            file.seekp((j+1)*sizeof(employee)); file.write((char*)&e1, sizeof(employee));
        }
    }

    file.close();
    std::cout << "file modified successfully!";

    return 0;
}