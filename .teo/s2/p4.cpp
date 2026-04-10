/*
    Example 4.
    Given N integers and an integer x, return the list with all 'x' eliminated from it.
*/

#include <iostream>

int main() {

    int N;
    std::cin >> N;

    int list[N];

    for (int i = 0; i < N; i++) {
        std::cin >> list[i];
    }

    int exclude;
    std:: cin >> exclude;

    int t[N], j = 0;
    for (int i = 0; i < N; i++) {
        if (list[i] != exclude) {
            t[j] = list[i];
            j++;
        }
    }

    // then, j is the length of the new list
    int newList[j];
    for (int i = 0; i < j; i++) {
        newList[i] = t[i];
    }

    // print
    for (int l : newList) {
        std::cout << l << " ";
    }

    return 0;
}