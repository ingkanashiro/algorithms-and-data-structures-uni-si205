#include <iostream>

struct node {
    int code;
    float avg;

    node* ptr;
};

void newnode(node* &p, int code, float avg) {
    p = new(node);

    p->code = code;
    p->avg = avg;
    p->ptr = NULL;
}


void stackin(node* &p) {
    node* q;
    
    int n;
    do { std::cin >> n; } while (n < 1);

    p = NULL; //empty stack

    int code; float avg;

    for (int i = 0; i < n; i++) {
        std::cin >> code >> avg;

        if (p == NULL) {
            newnode(p, code, avg);
        }
        else {
            newnode(q, code, avg);
            q->ptr = p;
            p = q;
        }
    }
}

void llout(node* p) {
    while (p != NULL) {
        std::cout << p->code << '\t' << p->avg << std::endl;
        p = p->ptr;
    }
}

int main() {

    node* stack;
    stackin(stack);

    llout(stack);
    return 0;
}