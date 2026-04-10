/*
    Example 3.
    Given a list of N students, we wish to store their id (3 digits), age (2 digits) and gender (char F/M).
    Then, present the sorted list with respect of their age and, if equal, respect of their id.
*/

#include <iostream>

int main() {

    // given the age has preference over the id, we can concatenate the two data.

    int N;
    std::cin >> N;

    int code[N];
    int age[N];
    int index[N];
    int val[N]; // the sorting value, composed by age and code adjacently.
    char gender[N];

    for (int i = 0; i < N; i++) {
        std::cin >> code[i] >> age[i] >> gender[i];
        val[i] = (age[i] * 1000) + code[i];
        index[i] = i;
    }

    // Sort respect of val
    for (int i = 0; i < N; i++) for (int j = 0; j < N - 1; j++) {
        if (val[index[j]] > val[index[j + 1]]) {
            std::swap(index[j], index[j+1]);
        }       
    }

    // Index will be sorted respect of val
    std::cout << "*** SORTED LIST ***" << std::endl;
    for (int i : index) {
        std::cout << code[i] << " " << age[i] << " " << gender[i] << std::endl;
    }

    return 0;
}