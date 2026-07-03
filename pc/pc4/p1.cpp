#include <iostream>
#include <fstream>

typedef char string[3];

struct score {
    int val;

    score *ptr;
};

struct section {
    char id;

    section *ptr;
    score *l;
};

void newnode(score *&p, int val) {
    if (p == NULL) {
        p = new(score);

        p->val = val;
        p->ptr = NULL;
    }
    else {
        newnode(p->ptr, val);
    }
}

void insert(score *&p, score *&prev, int val) { // descending order
    
    if (p == NULL) {
        p = new(score);

        p->val = val;
        p->ptr = NULL;
    }
    else if (val > p->val) { // val = 10
        score *q = new(score);

        q->val = val;
        q->ptr = p;

        prev->ptr = q;
    }
    else {
        insert(p->ptr, p, val);
    }
    
}

void newnode2(section *&s, char id, int val) {

    if (s == NULL) {
        s = new(section);

        s->id = id;
        s->ptr = NULL; s->l = NULL;

        newnode(s->l, val);
    }
    else if (s->id == id) {
        insert(s->l->ptr, s->l, val);
    }
    else {
        newnode2(s->ptr, id, val);
    }
}

void print(score *p, int &a, int&f) {

    if (p != NULL) {

        // count passed vs failed scores

        if (p->val < 10) {
            f++;
        }
        else {
            a++;
        }

        std::cout << p->val << '\t';

        print(p->ptr, a, f);
    }
    else {
        std::cout << std::endl;
    }
}

void print2(section *s) {

    if (s != NULL) {
        std::cout << "Sección " << s->id << ":" << std::endl << "Notas: ";
        
        int a = 0, f = 0;
        print(s->l, a, f);

        std::cout << "Aprobados: " << a << std::endl << "Desaprobados: " << f << std::endl;

        print2(s->ptr);
    }
    else {
        std::cout << std::endl;
    }
}

int main() {

    std::ifstream file;
    file.open("NOTASPC4.TXT");
    
    section *list = NULL;

    if (!file) {
        std::cout << "No se encontró el archivo NOTASPC4.TXT o hubo un problema al abrirlo." << std::endl;
    }
    else {
        while (!file.eof()) {

            string data;
            if (file >> data) {

                char section = data[0];
                int sc = 10*(data[1] - '0') + (data[2] - '0');
                
                newnode2(list, section, sc);
            }    
        }
    }

    file.close();

    // list is made
    print2(list);

    return 0;
}