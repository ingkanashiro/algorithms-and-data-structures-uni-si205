/*
    Example 2.
    Given N employees, store their employee code (3 digits) and their payroll.
    Then, order in descending order in function of the payroll.
*/

#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;

    int codes[N], payroll[N], index[N];

    for (int i = 0; i < N; i++) {
        cin >> codes[i] >> payroll[i];
        index[i] = i;
    }

    // Bubble sort
    for (int i = 0; i < N; i++) for (int j = 0; j < N - 1; j++) {
        if (payroll[index[j]] > payroll[index[j + 1]]) {
            swap(index[j], index[j + 1]);
        }
    }

    cout << endl << "*** ORDERED LIST ***" << endl;

    for (int i = N - 1; i >= 0; i--) {
        cout << i[index][codes] << ": " << payroll[index[i]] << endl;
    }

    return 0;
}