#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    double discountPrice, originalPrice;
    
    cout << "Precio descontado al 20%: $ ";
    cin >> discountPrice;

    // since discountPrice = originalPrice * (80%), then originalPrice = discountPrice * (5 / 4)
    originalPrice = 1.25 * discountPrice;

    cout << fixed << setprecision(2);
    cout << "Precio original: $ " << originalPrice << endl;

    return 0;
}