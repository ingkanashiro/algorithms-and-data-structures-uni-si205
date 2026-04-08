#include <iostream>

using namespace std;

int main() {

    int num;
    cin >> num;

    cout << num << ((num > 100) ? " es" : " no es") << " mayor que 100 y " << 
            ((num % 11 == 0) ? "es" : "no es") << " divisible por 11" << endl;
            
    return 0;
}