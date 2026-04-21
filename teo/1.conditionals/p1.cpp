#include <iostream>

using namespace std;

int main() {
    
    int a, b;
    cin >> a >> b;

    // Notice int division is implicit floor(...)

    int max = (a * (a / b) + b * (b / a)) / (a / b + b / a);
    int min = (b * (a / b) + a * (b / a)) / (a / b + b / a);

    cout << "max: " << max << '\n';
    cout << "min: " << min << '\n';

    return 0;
}
