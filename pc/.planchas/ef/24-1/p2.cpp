#include <iostream>
#include <cstring>

typedef char string[64];

struct node {
    string exp;
    node *ptr;
};

// 5 4 + 3 2 * *
// 9 6 *
// 54

void newnode(node *&p, string exp) {
    if (p == NULL) {
        p = new(node);

        strcpy(p->exp, exp);
        p->ptr = NULL;

        std::cout << "element: " << exp << std::endl;
    }
    else {
        newnode(p->ptr, exp);
    }
}

void getexpr(node *&p) {
    
    p = NULL;
    string exp;

    fflush(stdin);
    gets(exp);

    string e; int k = 0;
    for (int i = 0; i < strlen(exp); i++) {

        if (exp[i] != ' ') {

            e[k++] = exp[i];

            if (exp[i+1] == ' ') {
                e[k++] = 0;
                k = 0;

                newnode(p, e);
                strcpy(e, "");
            }
        }
    }
}

bool isNumerical(string str) {
    for (int i = 0; i < strlen(str); i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-') {
            return false;
        }
    }

    return true;
}

void operate(string &dest, string x, string y, string f) {

    int r;
    if (strcmp(f, "+") == 0) {
        r = atoi(x) + atoi(y);
    }
    else if (strcmp(f, "-") == 0) {
        r = atoi(x) - atoi(y);
    }
    else if (strcmp(f, "*") == 0) {
        r = atoi(x) * atoi(y);
    }
    else if (strcmp(f, "/") == 0) {
        r = atoi(x) / atoi(y);
    }
    else if (strcmp(f, "^") == 0) {
        r = 1;

        for (int i = 0; i < atoi(y); i++) {
            r *= atoi(x);
        }
    }

    itoa(r, dest, 10);
}

void eval(node *&p) {

    if (p->ptr == NULL) {
        return;
    }

    node *q = p, *prev = NULL;

    while (q->ptr != NULL) {
        if (q->ptr->ptr == NULL) {
            break;
        }

        if (isNumerical(q->exp) && isNumerical(q->ptr->exp) && !isNumerical(q->ptr->ptr->exp)) {
            // reduce nodes
            node *r = new(node);
            
            operate(r->exp, q->exp, q->ptr->exp, q->ptr->ptr->exp);
            if (prev != NULL) {
                prev->ptr = r;
            }
            
            r->ptr = q->ptr->ptr->ptr;
            q = r;
        }

        prev = q;
        q = q->ptr;
    }

    eval(p);
}

int main() {

    node *exp;
    getexpr(exp);

    eval(exp);

    std::cout << "= " << exp->exp << std::endl;
    
    return 0;
}