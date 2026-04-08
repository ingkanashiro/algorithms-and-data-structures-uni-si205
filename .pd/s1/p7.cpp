#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    double capital, aug1, aug2;
    cin >> capital >> aug1 >> aug2;

    cout << fixed << setprecision(2);
    cout << '\n' << "$ " << capital << " -> (+" << aug1 << "%) -> (+" << aug2 << "%) -> $ ";
    
    double result = capital * (aug1 + 100) * (aug2 + 100) / (10000);
    cout << result << endl;
    
    return 0;
}