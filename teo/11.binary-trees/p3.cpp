#include <iostream>
#include <fstream>
#include <cstring>

typedef char string[3];

struct student {
    int code;
    float avg;

    student *l, *r;
};

struct specialty {
    string sp;

    specialty *l, *r;
    student *s;
};

void newnode(student *&p, int code, float avg) {
    if (p == NULL) {
        p = new(student);
    
        p->code = code;
        p->avg = avg;

        p->l = NULL, p->r = NULL;
    }
    else if (avg < p->avg) {
        newnode(p->l, code, avg);
    }
    else {
        newnode(p->r, code, avg);
    }
}

void newnode(specialty *&p, string sp, int code, float avg) {
    if (p == NULL) {
        p = new(specialty);

        strcpy(p->sp, sp);
        p->l = NULL; p->r = NULL;
        p->s = NULL;

        newnode(p->s, code, avg);
    }
    else if (strcmp(sp, p->sp) == 0) {
        newnode(p->s, code, avg);
    }
    else if (strcmp(sp, p->sp) > 0) {
        newnode(p->l, sp, code, avg);
    }
    else {
        newnode(p->r, sp, code, avg);
    }
}

void nodeout(student *p) {
    if (p != NULL) {
        nodeout(p->r);
        std::cout << '\t' << p->code << '\t' << p->avg << std::endl;
        nodeout(p->l);
    }
}

void treeout(specialty *T) {
    if (T != NULL) {
        treeout(T->r);
        std::cout << T->sp << ":" << std::endl;
        nodeout(T->s);
        treeout(T->l);
    }
}

void treeinf(specialty *&T) {

    T = NULL;

    std::ifstream file;
    file.open("alumnos.txt");

    if (!file) {
        throw std::runtime_error("couldn't open file alumnos.txt");
    }

    while (!file.eof()) {

        string sp; int code; float avg;
        if (file >> code >> avg >> sp) {
            newnode(T, sp, code, avg);
        }

    }

    file.close();
}

int main() {

    specialty *T;
    treeinf(T);

    std::cout << "~~~~~~~~~~ RESULTS ~~~~~~~~~~" << std::endl;
    treeout(T);

    return 0;
}