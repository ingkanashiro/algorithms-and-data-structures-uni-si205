/*
    Example 6.
    Given a list of N products, each with their id and quantity, return a list with all the products, adding up
    all the products with the same id.
*/

// ESTA SOLUCIÓN UTILIZA CLASES, PERO PUEDE SOLUCIONARSE SIN UTILIZAR CLASES.

#include <iostream>

class Product {
    
    public:
        Product() {}
        Product(int id, int quantity) : id(id), quantity(quantity) {}
        
        void add(int x) {
            quantity += x;
        }

        const int getId() const {
            return id;
        }

        const void print() const {
            std::cout << id << " " << quantity << std::endl;
        }

    private:
        int id;
        int quantity;
};

int main() {

    int N;
    std::cin >> N;

    Product list[N];

    int numOfProducts = 0;
    for (int i = 0; i < N; i++) {
        int id, quantity;

        std::cin >> id >> quantity;

        bool isAlreadyAdded = false;
        for (int j = 0; j < numOfProducts; j++) {
            if (list[j].getId() == id) {
                list[j].add(quantity);
                isAlreadyAdded = true;
                break;
            }
        }

        if (!isAlreadyAdded) {
            Product newProduct(id, quantity);
            list[numOfProducts] = newProduct;
            numOfProducts++;
        }
    }

    Product fixedList[numOfProducts];

    for (int i = 0; i < numOfProducts; i++) {
        fixedList[i] = list[i];
    }

    std::cout << "*** PRODUCTS ***" << std::endl;

    for (Product p : fixedList) {
        p.print();
    }

    return 0;
}