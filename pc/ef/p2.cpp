#include <iostream>
#include <string.h>

typedef char string[32];

struct node {
    int code;
    string name;

    node *l, *r;
};

void newnode(node *&p, int code, string name) {

    if (p == NULL) {
        p = new(node);

        p->code = code;
        strcpy(p->name, name);

        p->l = NULL; p->r = NULL;
    }
    else if (code < p->code) {
        newnode(p->l, code, name);
    }
    else {
        newnode(p->r, code, name);
    }
}

void treeout(node *p) {
    if (p != NULL) {
        treeout(p->l);
        std::cout << "\t" << p->code << " " << p->name << std::endl;
        treeout(p->r);
    }
}

void atreeout(node *p) {
    if (p != NULL) {
        treeout(p->l);
        treeout(p->r);
        std::cout << "\t" << p->code << " " << p->name << std::endl;
    }
}

void rtreeout(node *p) {
    if (p != NULL) {
        std::cout << "\t" << p->code << " " << p->name << std::endl;
        treeout(p->l);
        treeout(p->r);
    }
}

void seekfor(node *&p, int code) {
    if (p != NULL) {
        
        if (p->code == code) {
            std::cout << "Se encontró:" << std::endl;
            std::cout << "\t" << p->name << " (" << code << ")" << std::endl;
        }
        else if (code < p->code) {
            seekfor(p->l, code);
        }
        else {
            seekfor(p->r, code);
        }
    }
    else {
        std::cout << "No se encontró un producto de código " << code << std::endl;
    }
}

int main() {

    node *tree = NULL;
    int op;

    do {

        std::cout << std::endl;
        std::cout << "--------------------------------" << std::endl;
        std::cout << "[1] Insertar producto" << std::endl;
        std::cout << "[2] Buscar producto por código" << std::endl;
        std::cout << "[3] Mostrar árbol en orden" << std::endl;
        std::cout << "[4] Mostrar árbol en preorden" << std::endl;
        std::cout << "[5] Mostrar árbol en postorden" << std::endl;
        std::cout << std::endl;
        std::cout << "[0] Terminar" << std::endl;
        std::cout << "--------------------------------" << std::endl;
        
        std::cout << "> "; std::cin >> op;
        std::cout << std::endl;
        
        int code; string name;

        switch (op) {
            case 1:
                std::cout << "Nuevo producto:" << std::endl;
                std::cout << "\tCódigo: "; std::cin >> code;
                std::cout << "\tNombre: "; std::cin.ignore(); gets(name); fflush(stdin);

                newnode(tree, code, name);
                break;

            case 2:
                std::cout << "Buscar producto de código... "; std::cin >> code;
                seekfor(tree, code);

                break;

            case 3:
                std::cout << "Lista en orden:" << std::endl;
                treeout(tree);
                break;
                
            case 4:
                std::cout << "Lista en preorden:" << std::endl;
                atreeout(tree);
                break;
                
            case 5:
                std::cout << "Lista en postorden:" << std::endl;
                rtreeout(tree);
                break;

            case 0:
                std::cout << "Terminando..." << std::endl;
                break;

            default:
                std::cout << "No se reconoció el comando [" << op << "]" << std::endl;
                break;
        }
        

    } while (op != 0);

    return 0;
}