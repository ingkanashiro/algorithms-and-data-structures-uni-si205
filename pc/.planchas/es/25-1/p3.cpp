#include <iostream>
#include <cstring>

typedef char string[32];

struct entry {
    string seller;
    int code;
    int quantity;
    float import;
};

void add(entry list[], int &k) {

    fflush(stdin);

    if (k > 99) {
        std::cerr << "Se ha alcanzado el límite de ventas de la lista." << std::endl;
        return;
    }

    entry e;
    
    std::cout << "\tVendedor: ";            gets(e.seller); fflush(stdin);
    std::cout << "\tCódigo del producto: "; std::cin >> e.code;
    std::cout << "\tCantidad: ";            std::cin >> e.quantity;
    std::cout << "\t          @ S/";       std::cin >> e.import;

    list[k] = e;
    k++;
}

void print(entry list[], int k) {

    std::cout << "--------------------------- LISTA ---------------------------" << std::endl;
    std::cout << "\tVendedor\t\tCod\t\tCantidad / Importe" << std::endl;
    for (int i = 0; i < k; i++) {
        std::cout << "\t" << list[i].seller << "\t\t" << list[i].code << "\t\t" << list[i].quantity << " @ S/" << list[i].import << std::endl;
    }
}

float getfrom(entry list[], int k, string seller) {

    float total = 0;
    for (int i = 0; i < k; i++) {
        if (strcmpi(list[i].seller, seller) == 0) {
            total += (list[i].quantity * list[i].import);
        }
    }

    std::cout << "\t" << seller << " vendió un total de S/" << total << std::endl;
    return total;
}

int getover(entry list[], int k, int i, float import) {

    if (i < k) {
        return (((list[i].import * list[i].quantity) > import) ? 1 : 0) + getover(list, k, i+1, import);
    }
    else {
        return 0;
    }
}


int main() {

    entry LIST[100]; int n = 0;

    int opt;
    do {
        std::cout << std::endl;
        
        std::cout << "----------------------------------" << std::endl;
        std::cout << "[1] Registrar nueva venta" << std::endl;
        std::cout << "[2] Mostrar ventas registradas" << std::endl;
        std::cout << "[3] Calcular total vendido por..." << std::endl;
        std::cout << "[4] Calcular número de ventas que superan..." << std::endl;
        std::cout << std::endl;
        std::cout << "[0] Terminar" << std::endl;
        std::cout << "----------------------------------" << std::endl;
        std::cout << "> "; std::cin >> opt;
        
        std::cout << std::endl;

        switch (opt) {
            case 1:
                add(LIST, n);
                break;

            case 2:
                print(LIST, n);
                break;

            case 3:
                string s; fflush(stdin);
                std::cout << "Vendedor: "; gets(s); fflush(stdin);
                getfrom(LIST, n, s);

                break;

            case 4:
                float x;
                std::cout << "Importe a superar: S/"; std::cin >> x;
                std::cout << getover(LIST, n, 0, x) << " ventas superan el importe de S/" << x << std::endl;
                
                break;
                
            case 0:
                std::cout << "Terminando..." << std::endl;
                break;

            default:
                std::cerr << "No se reconoció el comando [" << opt << "]" << std::endl;
                break;
        }

    }
    while (opt != 0);

    return 0;
}