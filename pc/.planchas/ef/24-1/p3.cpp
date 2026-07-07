#include <iostream>

struct node {
    int val;
    node *l, *r;
};

void newnode(node *&p, int val) {

    if (p == NULL) {
        p = new(node);

        p->val = val;
        p->l = NULL; p->r = NULL;
    }
    else if (val < p->val) {
        newnode(p->l, val);
    }
    else {
        newnode(p->r, val);
    }
}

void newtree(node *&t) {

    t = NULL;
    
    int n;
    do { std::cin >> n; } while (n < 1);

    while (n--) {
        int i;
        std::cin >> i;

        newnode(t, i);
    }
}

void height(int &h, node *p) {

    if (p == NULL) {
        h = 0;
    }
    else {
        int hl, hr;
        
        height(hl, p->l);
        height(hr, p->r);
        
        if (hl > hr) {
            h = hl + 1;
        }
        else {
            h = hr + 1;
        }    
    }
}

int main() {

    node *tree;
    newtree(tree);

    int h;
    height(h, tree);

    std::cout << "height: " << h << std::endl;

    return 0;
}