#include <iostream>
#include <fstream>

typedef char string[32];

struct student {
    int code;
    string name;
    float avg;
};

int main() {

    student s;
    std::fstream data, index;

    index.open("index.dat", std::ios::in);
    if (!index) {
        throw std::runtime_error("couldn't open index.dat");
    }
    
    data.open("registro.dat", std::ios::in);
    if (!data) {
        throw std::runtime_error("couldn't open registro.dat");
    }

    int n;
    index.seekg(0, index.end);
    n = index.tellg() / sizeof(int);
    index.seekg(0, index.beg);

    for (int i = 0; i < n; i++) {
        int j;
        
        index.seekg(i * sizeof(int));
        index.read((char*)&j, sizeof(int));

        data.seekg(j * sizeof(student));
        data.read((char*)&s, sizeof(student));

        std::cout << s.code << "\t\t" << s.name << "\t\t" << s.avg << std::endl;
    }

    data.close();
    index.close();

    return 0;
}