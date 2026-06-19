/*
    Example 10.
    Given a file "employees.txt", output the data of all employees per specialty.
    
    [EMPLOYEES.TXT]
        111     Contador        2500
        222     Administrador   3000
        333     Civil           1700
        444     Contador        2000
        555     Contador        3000

    Output:
        Contador:
            111     2500
            444     2000
            555     3000
        
        Administrador:
            222     3000

        Civil:
            333     1700
*/

#include <iostream>
#include <fstream>
#include <cstring>

typedef char string[32];

struct node {
    int code;
    float payroll;

    node *ptr;
};

struct list {
    string specialty;
    
    node *e;
    list *ptr;
};

void newnode(node *&p, int code, float payroll) {
    if (p == NULL) {
        p = new(node);
        
        p->code = code;
        p->payroll = payroll;
        p->ptr = NULL;
    }
    else {
        newnode(p->ptr, code, payroll);
    }
}

void newlist(list *&l, string specialty, int code, float payroll) {
    if (l == NULL) {
        l = new(list);

        strcpy(l->specialty, specialty);
        l->e = NULL; l->ptr = NULL;

        newnode(l->e, code, payroll);
    }
    else if (strcmp(specialty, l->specialty) == 0) {
        newnode(l->e, code, payroll);
    }
    else {
        newlist(l->ptr, specialty, code, payroll);
    }
}

void llout(node *&p) {
    if (p != NULL) {
        std::cout << '\t' << p->code << '\t' << p->payroll << std::endl;
        llout(p->ptr);
    }
}

void llout(list *&l) {
    if (l != NULL) {
        std::cout << std::endl << l->specialty << ":" << std::endl;
        llout(l->e);

        llout(l->ptr);
    }
}

void llqinf(list *&l) {
    l = NULL;

    int code; float payroll; string specialty;
    std::ifstream file;

    file.open("employees.txt");

    if (!file) {
        throw std::runtime_error("couldn't resolve file employees.txt");
    }

    while (!file.eof()) {
        if (file >> code >> specialty >> payroll) {
            newlist(l, specialty, code, payroll);
        }
    }

    file.close();
}

int main() {

    list *employees;
    llqinf(employees);

    llout(employees);

    return 0;
}