/*
    Example 6.
    Given three dates (dd/mm/yy), sort them latest to oldest.
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct date {
    int dd, mm, yy, index;
    string fmt;
};

int main() {

    string datesStr[3] = {};
    cout << "Input three dates (dd/mm/yy)" << '\n';
    cin >> datesStr[0] >> datesStr[1] >> datesStr[2];

    // vector<string> datesStr = {};
    // int size = 0;
    // string s;
    // do {
    //     cin >> s;
    //     if (s != "end") {
    //         datesStr.push_back(s);
    //         size++;
    //     }
    // }
    // while (s != "end");

    // We'll assume the dates are valid

    const int NUM_OF_DATES = 3;

    date dates[3] = {};
    for (int i = 0; i < NUM_OF_DATES; i++) {
        dates[i].dd = stoi(datesStr[i].substr(0, 2));
        dates[i].mm = stoi(datesStr[i].substr(3, 2));
        dates[i].yy = stoi(datesStr[i].substr(6, 2));

        dates[i].index = stoi(datesStr[i].substr(6, 2) + datesStr[i].substr(3, 2) + datesStr[i].substr(0, 2));
        
        dates[i].fmt = datesStr[i];
    }

    // Bubble sort dates[]

    while ([dates, NUM_OF_DATES](){

        bool ret = false;

        for (int i = 0; i < NUM_OF_DATES - 1; i++) {
            if (dates[i].index > dates[i + 1].index) {
                ret = true;
                break;
            }
        }

        return ret;

    }()) {
        
        for (int j = 0; j < NUM_OF_DATES - 1; j++) {
            if (dates[j].index > dates[j + 1].index) {
                swap(dates[j], dates[j + 1]);
            }
        }
    }

    date sortedDates[NUM_OF_DATES] = {};
    for (int i = 0; i < NUM_OF_DATES; i++) {
        sortedDates[i] = dates[NUM_OF_DATES - i - 1];
    }

    cout << "### SORTED LIST ###" << endl;
    for (int i = 0; i < NUM_OF_DATES; i++) {
        cout << sortedDates[i].fmt << endl;
    }

    return 0;
}