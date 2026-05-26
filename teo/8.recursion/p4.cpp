#include <iostream>

int cherrypick(int num, int d) {
    // 23543 -> (3)* -> 254 

    if (num == 0) return 0;

    if (num % 10 == d) {
        return cherrypick(num/10, d);
    }
    else {
        return (num % 10) + 10 * cherrypick(num/10, d);
    }
}

int main() {

    int num, digit;
    std::cin >> num >> digit;

    int modifiedNum = cherrypick(num, digit);
    std::cout << modifiedNum << std::endl;
    return 0;
}