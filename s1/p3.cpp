/*
    Example 3.
    Given three numbers, determine the minimum and how many instances of it there are.
*/

    #include <iostream>

    using namespace std;

    float min(float x, float y) {
        return x * (x < y) + y * (x >= y);
    }

    int main() {

        float a, b, c, q;
        int numOfInst = 0;

        cin >> a >> b >> c;

        q = min(min(a, b), c);
        numOfInst = (a == q) + (b == q) + (c == q);

        cout << "min: " << q << '\n';
        cout << "  i: " << numOfInst << '\n';

        return 0;
    }