#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int>& argz) {

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

int main() {

    vector<int> list;

    int t = 5;
    while (t--) {

        int in;
        cin >> in;

        list.push_back(in);
    }

    sort(list);

    int numOfIterations = 0;
    for (int l : list) {
        if (l != list[0]) {
            break;
        }
            
        numOfIterations++;
    }

    cout << "min: " << list[0] << endl;
    cout << "  i: " << numOfIterations << endl;

    return 0;
}