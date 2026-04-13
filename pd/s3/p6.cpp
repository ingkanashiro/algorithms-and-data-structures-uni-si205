#include <iostream>

struct person {

    int id;
    char gender;
    int age;

};

int main() {

    int n;
    std::cin >> n;

    person list[n];

    // Insertion sort

    int len = 0;
    for (int i = 0; i < n; i++) {
        
        person p;

        std::cin >> p.id >> p.gender >> p.age;

        if (p.id % 100 == 45) {
            continue;
        }

        if (len == 0) {
            list[0] = p;

            len++;
            continue;
        }

        int j = 0;
        while (j < len) {
            if (p.id < list[j].id) {

                // shift everything
                for (int r = len; r > j; r--) {
                    list[r] = list[r-1];
                }

                list[j] = p;

                break;
            }

            if (++j == len) {
                list[j] = p;
            }
        }

        len++;
    }

    std::cout << "*** SORTED DATA ***" << std::endl;
    for (int i = 0; i < len; i++) {
        std::cout << list[i].id << " " << list[i].age << list[i].gender << std::endl; 
    }

    return 0;
}