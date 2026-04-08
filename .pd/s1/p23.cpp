#include <iostream>
#include <iomanip>

using namespace std;

double ticketPrice(char type, double distance) {

    double TARIFF, DISCOUNT;

    switch (type) {
        
        case 'A':
            TARIFF = 26.7;
            DISCOUNT = 0.1;
            break;

        case 'B':
            TARIFF = 30.1;
            DISCOUNT = 0.12;
            break;

        case 'C':
            TARIFF = 25.8;
            DISCOUNT = 0.1;
            break;
    }

    return (distance * TARIFF * (1 - DISCOUNT));
}


int main() {

    char type;
    double distance;

    cin >> type >> distance;

    double price = ticketPrice(type, distance);

    cout << fixed << setprecision(2);
    cout << "price: $" << price << endl;

    return 0;
}