/*
    Example 6.
    Given three dates (dd/mm/yy), determine the latest.
*/

#include <iostream>

using namespace std;

struct date {
    int dd, mm, yy, index;
    string fmt;
};

int main() {

    string datesStr[3] = {};
    cout << "Input three dates (dd/mm/yy)" << '\n';
    cin >> datesStr[0] >> datesStr[1] >> datesStr[2];

    // We'll assume the dates are valid

    date dates[3] = {};
    for (int i = 0; i < 3; i++) {
        dates[i].dd = stoi(datesStr[i].substr(0, 2));
        dates[i].mm = stoi(datesStr[i].substr(3, 5));
        dates[i].yy = stoi(datesStr[i].substr(6, 8));

        dates[i].index = stoi(datesStr[i].substr(6, 8) + datesStr[i].substr(3, 5) + datesStr[i].substr(0, 2));
        dates[i].fmt = to_string(dates[i].dd) + "/" + to_string(dates[i].mm) + "/" + to_string(dates[i].yy);

        cout << i << " : " << dates[i].dd << "/" << dates[i].mm << "/" << dates[i].yy << endl;
    }

    // Find the latest
    int maxIndex = 0;
    for (int i = 0; i < 3; i++) {
        if (dates[i].index > dates[maxIndex].index) {
            maxIndex = i;
        }
    }

    cout << "The latest date is " << dates[maxIndex].fmt << endl;

    return 0;
}