#include <iostream>
#include <cstring>

// test case: La sonrisa cuesta menos que la electricidad pero da más luz

typedef char string[128];

struct word {
    string val;

    word *l, *r;
};

void llout(word *p) {
    if (p != NULL) {
        llout(p->l);
        std::cout << p->val << " ";
        llout(p->r);
    }
}

void newnode(word *&t, string val) {
    if (t == NULL) {
        t = new(word);
        strcpy(t->val, val);

        t->l = NULL; t->r = NULL;
    }
    else if (strlen(val) > strlen(t->val)) {
        newnode(t->l, val);
    }
    else {
        newnode(t->r, val);
    }
}

void llstr(word *&t, string arg) {

    t = NULL;

    string word; int k = 0;
    for (int i = 0; i < strlen(arg); i++) {
        if (arg[i] == ' ') {
            word[k] = 0;
            newnode(t, word);

            strcpy(word, "");
            k = 0;
        }
        else {
            word[k++] = arg[i];

            if (i == strlen(arg) - 1) {
                word[k] = 0;
                newnode(t, word);

                strcpy(word, "");
                k = 0;
            }
        }
    }
}

int main() {

    string in, out;
    gets(in); fflush(stdin);

    word *TREE;
    llstr(TREE, in);

    llout(TREE);

    return 0;
}