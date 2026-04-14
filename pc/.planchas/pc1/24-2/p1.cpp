#include <iostream>

int main() {

    int n;
    std::cin >> n;

    int streak = 1, maxStreak = 0;
    int num, prev;

    bool isFirstInput = true;
    while (n--) { // 1 2 3 4 0 1 2 0 3 4 5

        std::cin >> num;

        if (isFirstInput) {
            
            prev = num;
            isFirstInput = false;

            continue;
        }

        if (prev < num) {
            streak++;
        }
        else {
            if (maxStreak < streak) {
                maxStreak = streak;
            }
            streak = 1;
        }

        prev = num;

        if (n == 0 && maxStreak < streak) {
            maxStreak = streak;
        }
    }

    std::cout << "max streak: " << maxStreak << std::endl;

    return 0;
}