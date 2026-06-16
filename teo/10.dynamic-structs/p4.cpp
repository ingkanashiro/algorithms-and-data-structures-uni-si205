#include <iostream>

struct node {
    int code;
    float avg;

    node *ptr;
};

int main() {

    node *p, *q;

    p = new(node);
    q = new(node);

    p->code = 111; p->avg = 11.7; p->ptr = NULL;
    q->code = 222; q->avg = 14.5; q->ptr = NULL;

    p->ptr = q;

    std::cout << p->code << '\t' << p->avg << std::endl;
    p=p->ptr;
    
    std::cout << p->code << '\t' << p->avg << std::endl;

    return 0;
}