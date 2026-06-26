#include <iostream>

struct node {
    int code;
    float avg;

    node *ptr;
};

bool seekfor(node *&p, node *prev, node *curr, int code) {
    prev = NULL;
    curr = p;

    if (p == NULL) {
        return false;
    }

    while (curr != NULL) {
        if (curr->code == code) {
            return true;
        }

        prev = curr;
        curr = curr->ptr;
    }

    return false;
}

void delnode(node *&p, int code) {
    node *prev, *curr;
    bool isListed = seekfor(p, prev, curr, code);

    if (isListed) {
        if (curr = p) {
            p = p->ptr;
            delete curr;
        }
        else {
            prev->ptr = curr->ptr;
            delete curr;
        }
    }
    else {
        std::cout << "code " << code << " was not found" << std::endl;
    }
}

void insnode(node *&p, int code, float avg) {
    node *prev, *curr, *ins;
    bool isListed = seekfor(p, prev, curr, code);

    if (!isListed) {
        ins = new(node);

        ins->code = code;
        ins->avg = avg;
        ins->ptr = NULL;

        if (curr == p) {
            p = ins;
            ins->ptr = curr;
        }
        else {
            prev->ptr = ins;
            ins->ptr = curr;
        }
    }
    else {
        std::cout << "code " << code << " is already listed" << std::endl;
    }
}

void llout(node *p) {
    std::cout << std::endl;

    while (p != NULL) {
        std::cout << p->code << '\t' << p->avg << std::endl;
        p = p->ptr;
    }

    std::cout << std::endl;
}

void menu(node *&list, int &op) {
    int code; float avg;

    std::cout << "[1] Insert node" << std::endl;
    std::cout << "[2] Delete node" << std::endl;
    std::cout << "[3] Search node" << std::endl;
    std::cout << "[4] Print list" << std::endl << std::endl;
    std::cout << "[0] End process" << std::endl << std::endl;

    std::cin >> op;

    switch (op) {
        case 1:
            std::cout << std::endl << "inserting node: "; std::cin >> code >> avg;
            insnode(list, code, avg);
            break;
        
        case 2:
            std::cout << std::endl << "deleting node: "; std::cin >> code;
            delnode(list, code);
            break;

        case 3:
            std::cout << std::endl << "search for code: "; std::cin >> code;

            node *prev, *curr;
            if (seekfor(list, prev, curr, code)) {
                std::cout << "found code in list" << std::endl;
            }
            else {
                std::cout << "could not find code in list" << std::endl;
            }

            break;

        case 4:
            std::cout << std::endl << "list stands as: " << std::endl;
            llout(list);
            break;

        case 0:
            std::cout << std::endl << "process terminated." << std::endl;
            break;
    }
}

int main() {
    node *list;
    int op;

    int code; float avg;

    do {
        menu(list, op);
    } while (op != 0);

    return 0;
}