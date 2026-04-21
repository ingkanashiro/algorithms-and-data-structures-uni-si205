#include <iostream>

using namespace std;

double max(double x, double y) {
	return (x >= y) * x + (x < y) * y;
}

double min(double x, double y) {
	return (x >= y) * y + (x < y) * x;
}

int main() {
	
	double a, b;
	cin >> a >> b;
	
	cout << "max: " << max(a, b) << '\n';
	cout << "min: " << min(a, b);
	
	return 0;
}
