#include <iostream>
#include <cstring>

typedef char string[128];
typedef char sstring[6];

struct person {
    string names[3];
};

void cin(person &dest) {
    for (int i = 0; i < 3; i++) { 
        fflush(stdin); 
        gets(dest.names[i]);
    }

    std::cout << std::endl;
}

void gencodes(sstring dest[], person in[], int n) {

    for (int i = 0; i < n; i++) {

        sstring code;
        for (int j = 0; j < 3; j++) {
            code[j] = in[i].names[j][0];
        }

        int num = 1;
        for (int j = 0; j < i; j++) {
            if (dest[j][0] == code[0] && dest[j][1] == code[1] && dest[j][2] == code[2]) {
                num++;
            }
        }

        code[3] = '0' + (num / 10);
        code[4] = '0' + (num % 10);

        code[5] = 0;

        strcpy(dest[i], code);
    }
}


int main() {

    int n;
    do { std::cin >> n; } while (n < 1 || n > 99);

    person list[n];
    sstring codes[n];

    for (int i = 0; i < n; i++) {
        cin(list[i]);
    }

    // get the codes
    gencodes(codes, list, n);

    std::cout << std::endl << "Apellido paterno\tApellido materno\tNombre\t\tCódigo" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << list[i].names[0] << "\t\t\t" << list[i].names[1] << "\t\t\t" << list[i].names[2] << "\t\t" << codes[i] << std::endl;
    }

    return 0;
}