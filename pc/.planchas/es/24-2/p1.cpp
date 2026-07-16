#include <iostream>
#include <fstream>
#include <cstring>

typedef char string[20];

struct entry {
    int code;
    string brand;
    string model;
    float price;
    int year;
};

struct seller {
    int code;
    float import;
    int amount;

    seller *l, *r;
};

struct brand {
    string name;

    brand *l, *r;
    seller *head;
};

void fin() {

    std::fstream file;
    file.open("autos.dat", std::ios::in | std::ios::out);

    if (!file) {
        throw std::runtime_error("couldn't open file 'autos.dat'.");
    }

    int i = 0;
    while (true) {

        entry e;
        std::cin >> e.code;
        
        if (e.code == 0) {
            break;
        }
        
        std::cin >> e.brand >> e.model >> e.price >> e.year;
        std::cout << std::endl;

        // add to file.
        file.seekp(i*sizeof(entry));
        file.write((char*)&e, sizeof(entry));

        i++;
    }

    file.close();
}

void newnode(seller *&t, int code, float price) {
    if (t == NULL) {
        t = new(seller);

        t->code = code;
        t->import = price;
        t->amount = 1;
    }
    else if (code == t->code) {
        t->import += price;
        t->amount++;
    }
    else if (code < t->code) {
        newnode(t->l, code, price);
    }
    else {
        newnode(t->r, code, price);
    }
}

void newnode(brand *&t, string name, int code, float price) {
    if (t == NULL) {
        t = new(brand);

        strcpy(t->name, name);
        t->l = NULL; t->r = NULL; t->head = NULL;

        newnode(t->head, code, price);
    }
    else if (strcmpi(name, t->name) == 0) {
        newnode(t->head, code, price);
    }
    else if (strcmpi(name, t->name) < 0) {
        newnode(t->l, name, code, price);
    }
    else {
        newnode(t->r, name, code, price);
    }
}

void ftree(brand *&t) {

    std::fstream file;
    file.open("autos.dat", std::ios::in | std::ios::out);
    
    if (!file) {
        throw std::runtime_error("couldn't open file 'autos.dat'.");
    }

    file.seekg(0, file.end);
    int n = file.tellg() / sizeof(entry);
    file.seekg(0, file.beg);

    for (int i = 0; i < n; i++) {

        entry e;
        file.read((char*)&e, sizeof(entry));

        newnode(t, e.brand, e.code, e.price);
    }
}

void treeout(seller *t) {
    if (t != NULL) {
        treeout(t->l);
        
        float avg = t->import / t->amount;
        std::cout << "\t" << "Vendedor #" << t->code << "\tPromedio de ventas: S/" << avg << std::endl;
        
        treeout(t->r);
    }
    else {
        std::cout << std::endl;
    }
}

void treeout(brand *t) {
    if (t != NULL) {
        treeout(t->l);
        
        std::cout << t->name << ":" << std::endl;
        treeout(t->head);
        
        treeout(t->r);
    }
    else {
        std::cout << std::endl;
    }
}

int main() {

    fin();

    brand *TREE;
    ftree(TREE);

    treeout(TREE);

    return 0;
}