#include <iostream>

int main() {

    long long num;
    std::cin >> num;

    int prev = (num % 10);
    bool isFirstDigit = true;

    int streak = 1, maxStreak = 1;
    int maxStreakDigit = (num % 10);

    num /= 10;
    while (num) {

        int digit = (num % 10);

        if (digit == prev) {
            streak++;
        }   
        else {
            if (streak > maxStreak) {
                maxStreak = streak;
                maxStreakDigit = prev;

                streak = 1;
            }
        }

        if ((num /= 10) == 0 && streak > maxStreak) {
            maxStreak = streak;
            maxStreakDigit = prev;
        }
        
        prev = digit;
    }

    std::cout << "max streak: " << maxStreak << std::endl;
    std::cout << "     digit: " << maxStreakDigit << std::endl;

    return 0;
}