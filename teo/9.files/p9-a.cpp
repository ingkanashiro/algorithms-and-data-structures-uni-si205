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
    std::ofstream out;

    int n;
    std::cin >> n;

    out.open("registro.dat");

    if (!out) {
        throw std::runtime_error("couldn't open registro.dat");
    }

    for (int i = 0; i < n; i++) {
        std::cout << std::endl;
        std::cin >> s.code >> s.name >> s.avg;

        out.write((char*)&s, sizeof(s));
    }

    out.close();
    std::cout << "file written successfully!";

    return 0;
}