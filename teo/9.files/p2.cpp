#include <iostream>
#include <fstream>

typedef char string[64];

int main() {

    std::ifstream in;

    in.open("ALUMNOS.TXT");

    if (!in) {
        throw std::runtime_error("unexpected error whilst opening ALUMNOS.TXT");
    } 

    int code; string name; double avg;

    std::cout << "Código\t\tNombre\t\tPromedio" << std::endl;
    while (!in.eof()) {
        if (in >> code >> name >> avg) { 
            std::cout << code << "\t\t" << name << "\t\t" << avg << std::endl; 
        }
    }

    in.close();

    return 0;
}