/*
    Example 1.
    Given N ages between 15 and 40 years old, find the number of instances of each one.
*/

#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;

    int ageCount[26];
    for (int i = 0; i < 26; i++) {
        ageCount[i] = 0;
    }

    while (N--) {

        int age;
        cin >> age;

        ageCount[age - 15]++;
    }

    for (int i = 0; i < 26; i++) {
        if (ageCount[i] > 0) {
            cout << (i + 15) << ": " << ageCount[i] << endl;
        }
    }

    return 0;
}