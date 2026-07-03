#include <iostream>
#include <string.h>

typedef char string[32];

struct node {
    int id;
    string name;

    node *ptr;
};

void newnode(node *&p, int id, string name) {
    if (p == NULL) {
        p = new(node);

        p->id = id;
        strcpy(p->name, name);
    }
    else {
        newnode(p->ptr, id, name);
    }
}

void popback(node *&p, int &id, string &name) {

    if (p == NULL) {
        id = -1;
    }
    else {
        id = p->id;
        strcpy(name, p->name);

        p = p->ptr;
    }
}

void getnext(node *&p, int &id, string &name) {

    if (p == NULL) {
        id = -1;
    }
    else {
        id = p->id;
        strcpy(name, p->name);
    }
}

void llout(node *p) {

    if (p == NULL) {
        std::cout << std::endl;
    }
    else {
        std::cout << "^ " << p->name << '\t' << p->id << std::endl; 
        llout(p->ptr);
    }
}

int main() {

    int in;
    node *list = NULL;

    do {

        std::cout << "--------------------------" << std::endl << std::endl;

        std::cout << "[1] Registrar paciente" << std::endl;
        std::cout << "[2] Atender paciente" << std::endl;
        std::cout << "[3] Mostrar siguiente" << std::endl;
        std::cout << "[4] Mostrar cola" << std::endl << std::endl;

        std::cout << "[0] Terminar" << std::endl << std::endl;

        std::cout << "--------------------------" << std::endl << "> ";

        std::cin >> in;

        std::cout << std::endl;

        int id; string name;
        
        switch (in) {

            case 1:
                std::cout << "\tDNI: "; std::cin >> id;
                std::cout << "\tNombre: "; std::cin >> name;

                newnode(list, id, name);
                std::cout << "Se añadió al paciente " << name << " (" << id << ")." << std::endl;

                break;

            case 2:
                popback(list, id, name);

                if (id == -1) {
                    std::cout << "No hay pacientes en la cola." << std::endl;
                }
                else {
                    std::cout << "Se atendió al paciente " << name << " (" << id << ")." << std::endl;
                }
                
                break;
                
            case 3:
                getnext(list, id, name);

                if (id == -1) {
                    std::cout << "No hay pacientes en la cola." << std::endl;
                }
                else {
                    std::cout << "El siguiente paciente en la cola es " << name << " (" << id << ")." << std::endl;
                }

                break;

            case 4:
                std::cout << "Cola:" << std::endl;
                llout(list);
                break;

            case 0:
                std::cout << "Proceso finalizado." << std::endl;
                break;

            default:
                std::cout << "El comando [" << id << "] no se pudo reconocer." << std::endl;
                break;
        }

    } while (in != 0);

    return 0;
}