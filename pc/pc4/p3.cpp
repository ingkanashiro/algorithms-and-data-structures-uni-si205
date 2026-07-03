#include <iostream>

struct node {
    int val;

    node *ptr;
};

void fnewnode(node *&p, int val) {
    
    node *q = new(node);
    q->val = val;
    q->ptr = p;

    p = q;
}

void newnode(node *&p, int val) {
    if (p == NULL) {
        p = new(node);

        p->val = val;
        p->ptr = NULL;
    }
    else {
        newnode(p->ptr, val);
    }
}

void dellast(node *&p) {

    node *prev = NULL;

    while (p->ptr != NULL) {
        prev = p;
        p = p->ptr;
    }

    if (prev != NULL) {
        prev->ptr = NULL;
        p = prev;
    }
    else {
        p = NULL;
    }
}

void move(node *&s, node*&q) {

    node *prev = NULL;

    while (s->ptr != NULL) {
        prev = s;
        s = s->ptr;
    }

    newnode(q, s->val);

    if (prev != NULL) {
        prev->ptr = NULL;
        s = prev;
    }
    else {
        s = NULL;
    }
}

void lloutln(node *p) {

    if (p == NULL) {
        std::cout << "]";
    }
    else if (p->ptr == NULL) {
        std::cout << p->val << "]";
    }
    else {
        std::cout << p->val << ", ";
        lloutln(p->ptr);   
    }
}

int main() {

    node *stack = NULL, *queue = NULL;

    int n;
    do { std::cin >> n; } while (n < 1);

    for (int i = 0; i < n; i++) {

        int k;
        std::cin >> k;

        std::cout << "[" << (i+1) << "]\tEntrada: " << k << " ";

        if (k > 0) {
            std::cout << "(Positivo): Se añade a la Pila" << std::endl;
            newnode(stack, k);
        }
        else if (k == 0) {
            std::cout << "(Comando): Se elimina el elemento del tope de la Pila" << std::endl;
            dellast(stack);
        }
        else {
            std::cout << "(Negativo): Se mueve el tope de la Pila a la Cola" << std::endl;
            move(stack, queue);
        }

        std::cout << "\tPila: [";   lloutln(stack);
        std::cout << "\tCola: [";   lloutln(queue);

        std::cout << std::endl << std::endl;
    }


    return 0;
}