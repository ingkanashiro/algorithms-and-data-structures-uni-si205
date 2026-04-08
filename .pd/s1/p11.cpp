#include <iostream>
#include <vector>

using namespace std;

double min(vector<double> list) {

    double x = list[0];

    for (double l : list) {
        if (l < x) {
            x = l;
        }
    }

    return x;
}


int main() {

    double a, b, c;
    cin >> a >> b >> c;

    cout << "min: " << min({a, b, c});

}