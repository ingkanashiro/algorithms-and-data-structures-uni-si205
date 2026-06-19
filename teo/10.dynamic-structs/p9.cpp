/*
    Example 9.
    Recieve a data.txt file, containing a column of codes corresponding to certain products, and a second column with the number of units.
    Output the number of units for every product. Notice that product codes may repeat throughout the file, in that case, calculate the total.

    [DATA.TXT]
        111     300
        222     100
        111     150
        333     100
        111     200

*/

#include <iostream>
#include <fstream>

struct node {
    int code;
    int units;

    node *ptr;
};

void newnode(node *&p, int code, int units) {
    if (p == NULL) {
        p = new(node);

        p->code = code;
        p->units = units;
        p->ptr = NULL;
    }
    else if (code == p->code) {
        p->units += units;
    }
    else {
        newnode(p->ptr, code, units);
    }
}

void llqinf(node *&p) {
    
    int code, units;

    std::ifstream file;
    file.open("data.txt");

    if (!file) {
        throw std::runtime_error("couldn't resolve file data.txt");
    }
    
    p = NULL;
    
    while (!file.eof()) {
        if (file >> code >> units) {
            newnode(p, code, units);
        }
    }

    file.close();
}

void llout(node *&p) {
    if (p != NULL) {
        std::cout << p->code << '\t' << p->units << std::endl;
        llout(p->ptr);
    }
}

int main() {

    node *products;

    llqinf(products);

    std::cout << std::endl;
    llout(products);

    return 0;
}