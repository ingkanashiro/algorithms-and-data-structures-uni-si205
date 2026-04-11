/*
    Sincelery, no clue what's this exercise doing here, as this should be under 3. arrays.
    
    You can implement this functionality without arrays, using a linked list instead, but this uses pointers and
    more advanced stuff that we should not be using.
*/

#include <iostream>

class Date {
    
    public:
        Date() {}

        Date(std::string str, bool isLong) {
            
            dd = stoi(str.substr(0, 2));
            mm = stoi(str.substr(3, 2));

            if (isLong) {
                yyyy = stoi(str.substr(6, 4));
                yy = yyyy % 100;
            }
            else {
                yy = stoi(str.substr(6, 2));
                yyyy = (yy < 30 ? 2000 : 1900) + yy;
            }

            this->str = std::to_string(dd) + "/" + std::to_string(mm) + "/" + std::to_string(yyyy);
        }

        int get() const {
            int val = (yyyy * 10000) + (mm * 100) + dd;
            return val;
        }

        void print() {
            std::cout << str << std::endl;
        }

    private:
        int dd, mm, yy, yyyy;
        std::string str;
};

int main() {

    int t;
    std::cin >> t;

    Date* dates = new Date[t];

    for (int i = 0; i < t; i++) {

        std::string arg;
        std::cin >> arg;

        dates[i] = Date(arg, arg.length() > 9);
    }

    // Bubble sort

    while ([&dates, t](){

        bool isSorted = true;

        for (int i = 0; i < t - 1; i++) {
            if (dates[i].get() > dates[i+1].get()) {
                std::swap(dates[i], dates[i+1]);
                isSorted = false;
            }
        }

        return isSorted;
    
    }()) {}
    
    std::cout << "\n*** SORTED LIST ***" << std::endl;
    for (int i = 0; i < t; i++) {
        dates[i].print();
    }

    return 0;
}