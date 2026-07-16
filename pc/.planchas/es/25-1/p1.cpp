#include <iostream>
#include <fstream>
#include <cstring>

typedef char string[32];

struct entry {
    int age;
    char sex;
    bool status;

    entry *ptr;
};

struct district {
    string name;

    entry *head;
    district *ptr;
};

void newnode(entry *&p, int age, char sex, bool status) {

    if (p == NULL || age > p->age) {
        entry *q = new entry;

        q->age = age;
        q->sex = sex;
        q->status = status;

        q->ptr = p;
        p = q;
    }
    else {
        newnode(p->ptr, age, sex, status);
    }
}

void newnode(district *&p, string name, int age, char sex, bool status) {

    if (p == NULL || strcmpi(name, p->name) < 0) {
        district *q = new district;

        strcpy(q->name, name);
        q->head = NULL; q->ptr = p;

        newnode(q->head, age, sex, status);

        p = q;
    }
    else if (strcmpi(name, p->name) < 0) {
        
    }
    else if (strcmpi(name, p->name) == 0) {
        newnode(p->head, age, sex, status);
    }
    else {
        newnode(p->ptr, name, age, sex, status);
    }
}

void fget(district *&p) {

    p = NULL;

    std::ifstream file;
    file.open("covid19.txt");

    if (!file) {
        throw std::runtime_error("couldn't resolve file 'covid19.txt'.");
    }

    while (!file.eof()) {

        string name; int age; char sex; string status_str; bool status;
        if (file >> name >> age >> sex >> status_str) {

            status = (strcmpi(status_str, "positivo") == 0);
            newnode(p, name, age, sex, status);
        }
    }

    file.close();
}

void llout(entry *list, int &p, int &n) {
    if (list != NULL) {
        std::cout << "\t\t" << list->age << "\t" << list->sex << "\t" << (list->status ? "POSITIVO" : "NEGATIVO") << std::endl;
        if (list->status) {
            p++;
        }
        else {
            n++;
        }

        llout(list->ptr, p, n);
    }
    else {
        std::cout << std::endl;
    }
}

void llout(district *list, int &p, int &n) {
    if (list != NULL) {
        std::cout << list->name << ":" << std::endl;
        llout(list->head, p, n);

        llout(list->ptr, p, n);
    }
    else {
        std::cout << std::endl;
    }
}

int main() {

    district *LIST;
    fget(LIST);

    int posTotal = 0, negTotal = 0;
    llout(LIST, posTotal, negTotal);

    std::cout << "Total de casos positivos: " << posTotal << std::endl;
    std::cout << "Total de casos negativos: " << negTotal << std::endl;

    return 0;
}