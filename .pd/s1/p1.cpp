/*
    Problem 1.
    Receive a certain amount in soles and return the equivalent in dollars.
    You may ask for the change value.
*/

#include <iostream>
#include <array>

using namespace std;

int main() {

    

    double moneySoles, moneyDollars, change;
    cout << "Amount in soles: ";
    cin >> moneySoles;

    cout << "Change: S/ 1 <> $ ";
    cin >> change;

    moneyDollars = moneySoles * change;
    cout << "S/ " << moneySoles << " = $ " << moneyDollars << endl;

    return 0;
}