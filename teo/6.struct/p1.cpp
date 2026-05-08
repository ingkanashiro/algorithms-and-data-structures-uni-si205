// Asignación, escritura y lectura de registros

#include <iostream>
#include <cstring>

typedef char string[31];

struct Foo {
    int code;
    string name;
    double payroll;
    char gender;
};

int main() {

    Foo r;

    r.code = 111;
    strcpy(r.name, "wawawa");
    r.payroll = 2500;
    r.gender = 'M';

    fflush(stdin);  // clear buffer before string input
    gets(r.name);

    return 0;
}