#include <iostream>
#include <vector>

using namespace std;

int main() {

    string input;
    cin >> input;

    string k = "";
    vector<int> date;

    for (char c : input) {

        if (c == '.' || c == '/') {
            
            date.push_back(stoi(k));        
            
            k = "";
            continue;
        }

        k += c;
    }

    date.push_back(stoi(k));

    const int MAX_DAY_FOR_MONTH[12] = {
        31, ((date[2] % 4 == 0 && date[2] % 400 != 0) ? 29 : 28), 31, 30, 31, 30, 31, 30, 30, 31, 30, 31
    };


    if (date[1] < 13 && date[1] > 0 && date[0] > 0 && date[0] < MAX_DAY_FOR_MONTH[date[1] - 1] && date[2] > 0) {
        cout << "Format is valid" << endl;
    }
    else {
        cout << "Format not valid" << endl;
    }

    return 0;
}