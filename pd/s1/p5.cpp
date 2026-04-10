#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int coins;
    cin >> coins;

    cout << coins << " monedas de 10 céntimos se traducen a:" << endl;

    int numSoles = (coins - (coins % 10)) / 10, 
        num50Cents = floor((coins % 10) / 5), 
        numCents = 10 * ((coins % 10) - 5 * num50Cents);

    cout << "> " << numSoles << " monedas de 1 SOL" << endl;
    cout << "+ " << num50Cents << " monedas de 50 CÉNTIMOS" << endl;
    cout << "+ " << numCents << " CÉNTIMOS SUELTOS" << endl;

    return 0;
}