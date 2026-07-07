#include <iostream>
#include <fstream>
#include <cstring>

struct node {
    int val;

    node *d, *r;
};

void newnode(node *&p, int val) {
    if (p == NULL) {
        p = new(node);

        p->val = val;
        p->d = NULL; p->r = NULL; 

        std::cout << "yay" << std::endl;
    }   
}

void tbin(node *&p) {

    p = NULL;

    std::ifstream file;
    file.open("valores.txt");

    if (!file) {
        throw std::runtime_error("couldn't open file valores.txt");
    }

    while (!file.eof()) {
        int i; char c;
        if (file >> i) {
            std::cout << i << '\t';
        }
        else if (file >> c && c == '\n') {
            std::cout << std::endl;
        } 
    }

    

    file.close();
}

void tbout(node *p) {

    node *q = p, *t = p;

    std::cout << "------------- TABLE -------------" << std::endl;
    while (q != NULL) {

        std::cout << t->val << "\t\t";
        t = t->r;

        if (t == NULL) {
            t = q->d;
            q = t;

            std::cout << std::endl;
        }
    }
}

int main() {

    node *T;

    tbin(T);
    tbout(T);
}