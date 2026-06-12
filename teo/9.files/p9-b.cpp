// sort with indexation file

#include <iostream>
#include <fstream>

typedef char string[32];

struct student {
    int code;
    string name;
    float avg;
};

int main() {
    
    std::fstream data, index;

    student s, t;
    int n;

    data.open("registro.dat", std::ios::in);

    if (!data) {
        throw std::runtime_error("couldn't open file registro.dat");
    }

    data.seekg(0, data.end);
    n = data.tellg() / sizeof(student);
    data.seekg(0, data.end);
    
    index.open("index.dat", std::ios::out);
    if (!index) {
        throw std::runtime_error("couldn't open file index.dat");
    }

    for (int i = 0; i < n; i++) {
        index.write((char*)&i, sizeof(i));
    }
    index.close();

    index.open("index.dat", std::ios::in | std::ios::out);
    if (!index) {
        throw std::runtime_error("couldn't open file index.dat");
    }

    for (int i = 0; i < n; i++) for (int j = 0; j < n-1; j++) {
        
        int p, q;
        
        index.seekg(j*sizeof(int));
        index.read((char*)&p, sizeof(int));
        
        index.seekg((j+1)*sizeof(int));
        index.read((char*)&q, sizeof(int));

        data.seekg(p*sizeof(student));
        data.read((char*)&s, sizeof(student));

        data.seekg(q*sizeof(student));
        data.read((char*)&t, sizeof(student));

        if (s.avg > t.avg) {
            index.seekp(j*sizeof(int));
            index.write((char*)&q, sizeof(int));
            
            index.seekp((j+1)*sizeof(int));
            index.write((char*)&p, sizeof(int));
        }
    }

    index.close();
    data.close();

    std::cout << "file written successfully!";
    
    return 0;
}