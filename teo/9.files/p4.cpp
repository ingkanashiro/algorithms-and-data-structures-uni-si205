#include <iostream>
#include <fstream>
#include <cstring>

typedef char string[32];

int main() {

    std::ifstream data, courses;
    data.open("DATOS.TXT");
    
    if (!data) {
        throw std::runtime_error("could not open data file DATOS.TXT");
    }

    while (!data.eof()) {
        int code; string name;
        if (data >> code >> name) {

            std::cout << code << "\t\t" << name << std::endl;
            courses.open("NCURSOS.TXT");

            if (!courses) {
                throw std::runtime_error("could not open data file NCURSOS.TXT");
            }

            while (!courses.eof()) {
                int codeFor, score, courseCount = 0; string course; double avg = 0;

                if (courses >> codeFor >> course >> score) {
                    if (codeFor == code) {
                        std::cout << "\t\t" << course << "\t\t" << score << std::endl;
                        avg += score;   courseCount++;
                    }
                }

                if (courseCount > 0) {
                    avg /= courseCount;
                }
                std::cout << "avg: " << avg << std::endl;
            }

            std::cout << std::endl;

            courses.close();
        }
    }

    data.close();

    return 0;
}