#include <iostream>
#include <fstream>
#include <cstring>

typedef char string[32];

struct entry {
    int code;
    string pname, mname;
    float avg;
    int pos;
};

// auxiliar function to read the .dat files
void print(string f) {

    std::ifstream file;
    file.open(f);

    if (!file) {
        throw std::runtime_error("couldn't read file.");
    }

    file.seekg(0, file.end);
    int n = file.tellg() / sizeof(entry);
    file.seekg(0, file.beg);

    std::cout << "\n#\t\tCod\t\tApellidos\t\tPromedio" << std::endl;
    for (int i = 0; i < n; i++) {
        entry e;

        file.seekg(i*sizeof(entry));
        file.read((char*)&e, sizeof(entry));

        std::cout << e.pos << "\t\t" << e.code << "\t\t" << e.pname << " " << e.mname << "\t\t" << e.avg << std::endl;
    }

    file.close();
}

void fget(int &p, int &f) {

    p = 0; f = 0;

    std::ifstream scores;
    scores.open("notas.txt");

    if (!scores) {
        throw std::runtime_error("couldn't resolve 'notas.txt'.");
    }

    std::ofstream passed, failed;
    passed.open("aprobados.dat"); failed.open("desaprobados.dat");

    if (!passed || !failed) {
        throw std::runtime_error("couldn't create files properly.");
    }

    int k = 1;
    while (!scores.eof()) {

        entry e; e.pos = k;
        if (scores >> e.code >> e.pname >> e.mname >> e.avg) {

            if (e.avg < 10) {

                failed.seekp(f*sizeof(entry));
                failed.write((char*)&e, sizeof(entry));

                f++;
            }
            else {

                passed.seekp(p*sizeof(entry));
                passed.write((char*)&e, sizeof(entry));

                p++;
            }
            
            k++;
        }
    }

    scores.close();
    passed.close();
    failed.close();
}

int main() {

    int passed, failed;
    fget(passed, failed);

    if (passed > failed) {
        std::cout << "Hay más estudiantes aprobados que desaprobados" << std::endl;
    }
    else if (passed == failed) {
        std::cout << "Hay igual cantidad de estudiantes aprobados que desaprobados" << std::endl;
    }
    else {
        std::cout << "Hay más estudiantes desaprobados que aprobados" << std::endl;
    }

    /* // print .dat files
    
    string fp, ff;
    strcpy(fp, "aprobados.dat");
    strcpy(ff, "desaprobados.dat");
    
    print(fp);
    print(ff);

    */
    
    return 0;
}