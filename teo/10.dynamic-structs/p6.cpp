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


void queuein(node* &p) {
    node *q, *r;

    int n;
    do { std::cin >> n; } while (n < 1);

    p = NULL;

    int code; float avg;
    
    for (int i = 0; i < n; i++) {
        std::cin >> code >> avg;

        if (p == NULL) {
            newnode(p, code, avg);
            q = p;
        }
        else {
            newnode(r, code, avg);
            q->ptr = r;
            q = r;
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

    node* queue;
    queuein(queue);

    llout(queue);
    return 0;
}