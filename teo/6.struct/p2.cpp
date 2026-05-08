// Arreglos de registros

#include <iostream>
#include <cstring>

typedef char string[31];

struct Foo {
    int code;
    string name;
    double payroll;
};

int main() {

    int n;
    do { std::cin >> n; } while (n <= 0);

    Foo list[n];
    for (int i = 0; i < n; i++) {
        do { std::cin >> list[i].code; } while (list[i].code < 100 || list[i].code > 999);
        fflush(stdin); gets(list[i].name);
        do { std::cin >> list[i].payroll; } while (list[i].payroll < 0);
    }

    for (int i = 0; i < n; i++) for (int j = 0; j < n-1; j++) {
        if (list[j].payroll > list[j+1].payroll) {
            std::swap(list[j], list[j+1]);
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << list[i].code << '\t' << list[i].name << "\t\t" << list[i].payroll << std::endl;
    }

    return 0;
}