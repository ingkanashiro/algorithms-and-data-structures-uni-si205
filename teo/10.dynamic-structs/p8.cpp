// Definición recursiva

#include <iostream>

struct node {
    int code;
    float avg;

    node *ptr;
};

void newnode(node *&p, int code, float avg) {
    if (p == NULL) {
        p = new(node);

        p->code = code;
        p->avg = avg;
        p->ptr = NULL;
    }
    else {
        newnode(p->ptr, code, avg);
    }
}

void llqin(node *&p) {
    int n;
    do { std::cin >> n; } while (n < 1);

    p = NULL;

    std::cout << '\n';
    for (int i = 0; i < n; i++) {

        int code; float avg;
        std::cin >> code >> avg;

        newnode(p, code, avg);
    }
}

void llout(node *&p) {
    if (p != NULL) {
        std::cout << p->code << '\t' << p->avg << std::endl;
        llout(p->ptr);
    }
}

int main() {

    node *queue;
    llqin(queue);

    llout(queue);
    
    return 0;
}