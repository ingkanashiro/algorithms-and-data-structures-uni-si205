#include <iostream>
#include <vector>
#include <array>

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

void reverse(vector<int>& argz) {

    vector<int> rev;

    for (int i = argz.size() - 1; i >= 0; i--) {
        rev.push_back(argz[i]);
    }

    argz = rev;
}

int main() {

    vector<int> list;
    
    int t = 4;
    while (t--) {
        int in;
        cin >> in;

        list.push_back(in);
    }

    sort(list);
    reverse(list);

    for (int l : list) {
        cout << l << " ";
    }

    return 0;
}