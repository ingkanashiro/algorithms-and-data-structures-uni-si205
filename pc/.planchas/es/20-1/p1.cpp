#include <iostream>
#include <fstream>
#include <cstring>

typedef char string[64];

struct entry {
    int age;
    char sex;

    entry *ptr;
};

struct district {
    string name;

    entry *head;
    district *ptr;
};

void newnode(entry *&p, int age, char sex) {
    if (p == NULL) {
        p = new entry;

        p->age = age;
        p->sex = sex;

        p->ptr = NULL;
    } 
    else {
        newnode(p->ptr, age, sex);
    }
}

void newnode(district *&p, string name, int age, char sex) {
    if (p == NULL) {
        p = new district;

        strcpy(p->name, name);
        p->head = NULL; p->ptr = NULL;

        newnode(p->head, age, sex);
    }
    else if (strcmpi(p->name, name) == 0) {
        newnode(p->head, age, sex);
    }
    else {
        newnode(p->ptr, name, age, sex);
    }
}

void fget(district *&p) {

    p = NULL;

    std::ifstream file;
    file.open("covid.txt");

    if (!file) {
        throw std::runtime_error("couldn't resolve 'covid.txt'.");
    }

    while (!file.eof()) {

        // expect dashes instead of spaces, as we can't pull the whole stdin stream from the file. ('LA-MOLINA', 'LOS-OLIVOS', ...)

        string name; int age; char sex;
        if (file >> name >> age >> sex) {
            newnode(p, name, age, sex);
        }
    }

    file.close();
}

void llout(entry *p) {
    if (p != NULL) {
        std::cout << "\t" << p->age << "\t" << p->sex << std::endl;
        llout(p->ptr);
    }
    else {
        std::cout << std::endl;
    }
}

void llout(district *p) {
    if (p != NULL) {
        std::cout << p->name << ";" << std::endl;
        llout(p->head);
        llout(p->ptr);
    }
    else {
        std::cout << std::endl;
    }
}

int main() {

    district *LIST;
    fget(LIST);

    llout(LIST);

    return 0;
}