/*
    Example 2.
    Given a file (pedidos.txt), return every product code with their respective total of units. Notice that for repeating codes, you must add up the unit amounts for
    the total amount to return.

    pedidos.txt
        222     300
        444     150
        111     200
        222     120
        444     200
*/

#include <iostream>
#include <fstream>

struct node {
    int code;
    int units;

    node *l, *r;
};

void newnode(node *&p, int code, int units) {
    if (p == NULL) {
        p = new(node);
        
        p->code = code;
        p->units = units;

        p->l = NULL; p->r = NULL;
    }
    else if (code == p->code) {
        p->units += units;
    }
    else if (code > p->code) {
        newnode(p->r, code, units);
    }
    else {
        newnode(p->l, code, units);
    }
}

void treeout(node *p) {
    if (p != NULL) {
        treeout(p->l);
        std::cout << p->code << '\t' << p->units << std::endl;
        treeout(p->r);
    }
}

void treein(node *&p) {
    
    p = NULL;
    
    std::ifstream file;
    file.open("pedidos.txt");

    if (!file) {
        std::cout << "error while reading pedidos.txt" << std::endl;
        return;
    }

    while (!file.eof()) {
        int code, units;
        if (file >> code >> units) {
            newnode(p, code, units);
        }
    }

    file.close();
}

int main() {

    node *T;
    treein(T);

    std::cout << "--- ordered list ---" << std::endl;
    treeout(T);

    return 0;
}
