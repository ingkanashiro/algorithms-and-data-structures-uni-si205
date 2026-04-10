#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    double capital, augment, discount;
    cin >> capital >> augment >> discount;

    cout << fixed << setprecision(2);
    cout << '\n' << "$ " << capital << " -> (+" << augment << "%) -> (-" << discount << "%) -> $ ";
    
    double result = capital * (100 + augment) * (100 - discount) / (10000);
    cout << result << endl;
    
    return 0;
}