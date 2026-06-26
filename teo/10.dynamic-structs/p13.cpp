/*
    Example 13.
    Input the quoefficients of two polynomials and return the quoefficients of the product of these polynomials.

    p(x) = 3x^3 - 2x
    q(x) = 2x^2 + x + 3

    r(x) = p(x)q(x) = 6x^5 + 3x^4 + 5x^3- 2x^2 - 6x
*/

#include <iostream>

struct node {
    float quoefficient;
    int pow;

    node *ptr;
};

void newnode(node *&p, float q, int pow) {
    if (p == NULL) {
        p = new(node);

        p->quoefficient = q;
        p->pow = pow;

        p->ptr = NULL;
    }
    else {
        newnode(p->ptr, q, pow);
    }
}

void plyout(node *&p, bool firstDigit) {
    
    if (p != NULL) {
        if (p->quoefficient < 0) {
            std::cout << "- ";
            
            if (p->quoefficient != -1 || p->pow == 0) {
                std::cout << -1 * p->quoefficient;
            }
            
        }
        else if (p->quoefficient > 0) {

            if (!firstDigit) {
                std::cout << "+ ";
            }
            
            if (p->quoefficient != 1 || p->pow == 0) {
                std::cout << p->quoefficient;
            }
        }

        if (p->pow == 1) {
            std::cout << "x";
        }
        else if (p->pow != 0) {
            std::cout << "x^" << p->pow;
        }
            
        std::cout << " ";

        plyout(p->ptr, false);
    }
    else {
        std::cout << std::endl;
    }
}

void newply(node *&p) {
    p = NULL;
    int n; float q;

    do { std::cin >> n; } while (n < 0);

    for (int i = n; i >= 0; i--) {
        std::cout << "x^" << i << ":\t"; std::cin >> q;

        newnode(p, q, i);
    }
}

int quoeffof(node *p, int pow) {

    node *curr = p;

    while (curr != NULL) {
        if (curr->pow == pow) {
            return curr->quoefficient;
        }

        curr = curr->ptr;
    }

    return 0;
}

void plymult(node *p, node *q, node *&dest) {
    dest = NULL;
    int n = p->pow + q->pow;

    for (int i = n; i >= 0; i--) {

        float quoeff = 0;

        // check for all pairs of subnodes for p and q such that pow(p) + pow(q) = i, add to the coefficient.
        node *pt, *qt;
        pt = p; qt = q;
        
        while (pt != NULL) {

            int qpow = i - pt->pow;
            float pp = pt->quoefficient, qq = quoeffof(qt, qpow);

            quoeff += (pp * qq);

            pt = pt->ptr;
        }

        newnode(dest, quoeff, i);
    }
}

int main() {

    node *p, *q, *r;
    
    std::cout << "p(x):" << std::endl;
    newply(p);
    
    std::cout << "q(x):" << std::endl;
    newply(q);

    std::cout << std::endl;
    std::cout << "p(x) = "; plyout(p, true);
    std::cout << "q(x) = "; plyout(q, true);
    
    std::cout << std::endl;
    std::cout << "p(x)q(x) = ";

    plymult(p, q, r);
    plyout(r, true);

    return 0;
}