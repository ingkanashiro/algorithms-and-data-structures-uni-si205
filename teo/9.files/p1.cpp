#include <iostream>
#include <fstream>

typedef char string[64];

int main() {
    
    std::ofstream out;
    out.open("ALUMNOS.TXT");

    if (!out) {  
        throw std::runtime_error("unexpected error whilst opening file ALUMNOS.txt");
    } 
    
    int n;
    do { std::cin >> n; } while (n < 1);

    std::cout << std::endl;


    for (int i = 0; i < n; i++) {
        int code; string name; double avg;

        std::cin >> code >> name >> avg;

        out << code << "\t\t" << name << "\t\t" << avg << std::endl;
    }

    out.close();
    std::cout << std::endl << "Data saved succesfully!" << std::endl;

    return 0;
}