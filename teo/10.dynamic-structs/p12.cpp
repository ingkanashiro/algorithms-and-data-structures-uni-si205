#include <iostream>
#include <fstream>
#include <cstring>

typedef char string[6];

struct course {
    string code;
    float avg;

    course *ptr;
};

struct student {
    int code;

    student *ptr;
    course *list;
};

void newnode(course *&p, string code, float avg) {
    if (p == NULL) {
        p = new(course);

        strcpy(p->code, code);
        p->avg = avg;

        p->ptr = NULL;
    }
    else {
        newnode(p->ptr, code, avg);
    }
}

void newnode(student *&p, int code, string course, float avg) {
    if (p == NULL) {
        p = new(student);

        p->code = code;
        p->list = NULL;
        p->ptr = NULL;

        newnode(p->list, course, avg);
    }
    else {

        if (p->code == code) {
            newnode(p->list, course, avg);
        }
        else {
            newnode(p->ptr, code, course, avg);
        }
    }
}

void llout(course *p) {
    if (p != NULL) {
        std::cout << '\t' << p->code << '\t' << p->avg << std::endl;
        llout(p->ptr);
    }
}

void llout(student *p) {
    if (p != NULL) {
        std::cout << p->code << ":" << std::endl;
        llout(p->list);

        std::cout << std::endl;
        llout(p->ptr);
    }
}

void llqin(student *&p) {
    std::ifstream in;
    int code; string course; float avg;

    p = NULL;
    in.open("ciclo.txt");

    if (!in) {
        std::cout << "error encountered whilst opening file ciclo.txt" << std::endl;
        return;
    }

    while (!in.eof()) {
        if (in >> code >> course >> avg) {
            newnode(p, code, course, avg);
        }
    }
    in.close();

    std::cout << "list created succesfully!" << std::endl << std::endl;
}

int main() {
    student *list;

    llqin(list);
    llout(list);
}