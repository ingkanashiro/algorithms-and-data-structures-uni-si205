#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

void sort(array<double, 5>& argz) {

    // Bubble sort

    while([argz](){

        bool isSorted = true;

        for (int i = 1; i < argz.size(); i++) {
            if (argz[i - 1] > argz[i]) {
                isSorted = false;
                break;
            }
        }

        return !isSorted;

    }()) {

        for (int i = 0; i < argz.size() - 1; i++) {
            if (argz[i] > argz[i + 1]) {
                swap(argz[i], argz[i + 1]);
            }
        }
        
    }
}

double avg(array<double, 5> scores, int drop) {

    sort(scores);

    for (double d : scores) {
        cout << d << " ";
    }

    double result = 0;
    for (int i = drop; i < scores.size(); i++) {
        result += scores[i];
    }

    result /= (5 - drop);

    return result;
}



int main() {

    array<double, 5> scores;
    cin >> scores[0] >> scores[1] >> scores[2] >> scores[3] >> scores[4];

    double average = avg(scores, 2);

    cout << "avg: " << average << endl;

    return 0;
}