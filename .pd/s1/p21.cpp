#include <iostream>
#include <vector>
#include <array>

using namespace std;

void sort(vector<double>& argz) {

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

void reverse(vector<double>& argz) {

    vector<double> rev;

    for (int i = argz.size() - 1; i >= 0; i--) {
        rev.push_back(argz[i]);
    }

    argz = rev;
}

int main() {

    vector<double> scores_U, scores_V;

    int t = 4;
    while (t--) {

        char section;
        double score;

        cin >> section >> score;

        if (section == 'U') {
            scores_U.push_back(score);
        }
        else if (section == 'V') {
            scores_V.push_back(score);
        }
        else {
            throw runtime_error("section " + to_string(section) + " does not exist.");
        }
    }

    sort(scores_U);
    reverse(scores_U);

    sort(scores_V);
    reverse(scores_V);


    cout << "*** SECTION U ***" << endl;
    for (double s : scores_U) {
        cout << s << " ";
    }

    cout << endl << endl;
    cout << "*** SECTION V ***" << endl;
    for (double s : scores_V) {
        cout << s << " ";
    }

    return 0;
}