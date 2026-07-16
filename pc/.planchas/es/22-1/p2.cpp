#include <iostream>
#include <fstream>
#include <cstring>

typedef char string[64];

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
    if (p == NULL) {
        p = new(entry);

        p->age = age;
        p->sex = sex;
        p->status = status;

        p->ptr = NULL;
    }
    else {
        newnode(p->ptr, age, sex, status);
    }
}

void newnode(district *&p, string name, int age, char sex, bool status) {
    if (p == NULL) {
        p = new(district);

        strcpy(p->name, name);
        p->head = NULL; p->ptr = NULL;

        newnode(p->head, age, sex, status);
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
        string name; int age; char sex; string st_str; bool status;

        // we can't pull the whole stdin stream for a file, so we'll expect dashes. ('LA-MOLINA', 'LOS-OLIVOS', ...)
        if (file >> age >> sex >> st_str >> name) { 
            status = (strcmpi(st_str, "positivo") == 0);
            newnode(p, name, age, sex, status);
        }
    }

    file.close();
}

int maxcases(district *p) {
    int max = 0;

    while (p != NULL) {

        int cases = 0;

        entry *q = p->head;
        while (q != NULL) {

            if (q->status) {
                cases++;
            }

            q = q->ptr;
        }

        if (cases > max) {
            max = cases;
        }

        p = p->ptr;
    }

    return max;
}

void llout(entry *p) {
    if (p != NULL) {
        if (p->status) {
            std::cout << "\t" << p->age << "\t" << p->sex << std::endl;
        }

        llout(p->ptr);
    }
    else {
        std::cout << std::endl;
    }
}

void llpop(district *p) {
    std::cout << p->name << ":" << std::endl;
    llout(p->head);
}

void print(district *p, int cases) {
    while (p != NULL) {

        int c = 0;

        entry *q = p->head;
        while (q != NULL) {
            if (q->status) {
                c++;
            }

            q = q->ptr;
        }

        if (c == cases) {
            llpop(p);
        }

        p = p->ptr;
    }
}

int main() {

    district *LIST;
    fget(LIST);
    
    print(LIST, maxcases(LIST));

    return 0;
}