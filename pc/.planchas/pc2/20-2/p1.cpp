#include <iostream>
#include <ctime>

int main() {

    srand(time(NULL));

    int ticket;
    do { std::cin >> ticket; } while (ticket <= 1900);

    ticket *= 100; ticket += ((rand() % 12) + 1);

    std::cout << "ticket: " << ticket << std::endl;

    int val = 0;

    int T = ticket, d = 7;
    while (T) {
        val += ((T%10)*d);
        T /= 10; d--;
    }

    val %= 11;

    int prize;
    if (val > 1 && val < 8) {
        prize = 1000 * val;
    }
    else {
        prize = 0;
    }

    std::cout << " prize: S/ " << prize << ".00" << std::endl;

    return 0;
}