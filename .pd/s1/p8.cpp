#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    double capital, discount1, discount2;
    cin >> capital >> discount1 >> discount2;

    cout << fixed << setprecision(2);
    cout << '\n' << "$ " << capital << " -> (-" << discount1 << "%) -> (-" << discount2 << "%) -> $ ";
    
    double result = capital * (100 - discount1) * (100 - discount2) / (10000);
    cout << result << endl;
    
    return 0;
}