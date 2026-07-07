#include <iostream>

struct node {
    int val;
    node *ptr;
};

struct tree {
    int val;
    tree *l, *r;
};

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

void newtree(tree *&t, int val) {
    if (t == NULL) {
        t = new(tree);

        t->val = val;
        t->l = NULL; t->r = NULL;
    }
    else if (val < t->val) {
        newtree(t->l, val);
    }
    else {
        newtree(t->r, val);
    }
}

void collapse(tree *&t, node *&p) {

    if (t != NULL) {
        collapse(t->l, p);
        newnode(p, t->val);
        collapse(t->r, p);
    }
}

void treein(tree *&t) {
    int n;
    do { std::cin >> n; } while (n < 1);

    t = NULL;

    for (int i = 0; i < n; i++) {
        int v;
        std::cin >> v;

        newtree(t, v);
    }
}

void llout(node *&p) {
    if (p != NULL) {
        std::cout << "* " << p->val << std::endl;
        llout(p->ptr);
    }
}

int main() {

    node *list = NULL;
    tree *tree = NULL;

    treein(tree);
    collapse(tree, list);

    std::cout << std::endl << "--- RESULTING LIST ---" << std::endl;
    llout(list);



    return 0;
}