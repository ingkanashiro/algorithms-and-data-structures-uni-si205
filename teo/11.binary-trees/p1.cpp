#include <iostream>

struct node {
    int code;
    float avg;

    node *l, *r;
};

void newnode(node *&p, int code, float avg) {
    if (p == NULL) {
        p = new(node);

        p->code = code;
        p->avg = avg;

        p->l = NULL; p->r = NULL;
    }
    else if (p->avg < avg) {
        newnode(p->r, code, avg);
    }
    else {
        newnode(p->l, code, avg);
    }
}

void treeout(node *p) {
    if (p != NULL) {
        treeout(p->l);
        std::cout << p->code << "\t" << p->avg << std::endl;
        treeout(p->r);
    }
}

void treein(node *&p, int n) {
    p = NULL;

    while (n--) {
        int code; float avg;
        std::cin >> code >> avg;

        newnode(p, code, avg);
    }
}

int main() {

    node *T;
    int n;

    do { std::cin >> n; } while (n < 1);

    treein(T, n);

    std::cout << std::endl << std::endl << "--- ordered list ---" << std::endl;
    treeout(T);

    return 0;
}