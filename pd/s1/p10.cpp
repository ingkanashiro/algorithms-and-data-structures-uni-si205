#include <iostream>

using namespace std;

int main() {

    int num;
    cin >> num;

    cout << num << ((num % 7 == 0) ? " SÍ " : " NO ") << "es un múltiplo de 7" << endl;
    return 0;
}