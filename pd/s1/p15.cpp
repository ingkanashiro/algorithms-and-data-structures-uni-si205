#include <iostream>
#include <vector>

using namespace std;

double minPositive(vector<double> list) {

    double min = 0;

    for (double l : list) {

        if (l <= 0) {
            continue;
        }

        if (l < min || min == 0) {
            min = l;
        }
    }

    return min;
}

double maxNegative(vector<double> list) {

    double max = 0;

    for (double l : list) {

        if (l >= 0) {
            continue;
        }

        if (l > max || max == 0) {
            max = l;
        }
    }

    return max;
}


int main() {

    double a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    cout << a << " " << b << " " << c << " " << d << " " << e << endl;

    cout << "min: " << minPositive({a, b, c, d, e}) << endl;
    cout << "max: " << maxNegative({a, b, c, d, e});

    return 0;
}