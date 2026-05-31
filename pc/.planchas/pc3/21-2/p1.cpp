#include <iostream>

bool isLeap(int year) {
    return (year % 4 == 0) && !(year % 100 == 0 && year % 400 != 0);
}

int daysfor(int month, int year) {
    switch (month) {
        case 1:     return 31;                          break;
        case 2:     return (isLeap(year) ? 29 : 28);    break;
        case 3:     return 31;                          break;
        case 4:     return 30;                          break;
        case 5:     return 31;                          break;
        case 6:     return 30;                          break;
        case 7:     return 31;                          break;
        case 8:     return 31;                          break;
        case 9:     return 30;                          break;
        case 10:    return 31;                          break;
        case 11:    return 30;                          break;
        case 12:    return 31;                          break;
        default:    return -1;                          break;
    }
}

bool isValid(int d, int m, int y) {
    return (d > 0 && d <= daysfor(m, y));   // will return false for invalid months because daysfor(m) = -1
}

int datecmp(int d1, int m1, int y1, int d2, int m2, int y2) {
    int totalTime = 0; 
    
    if (y1*10000 + m1*100 + d1 > y2*10000 + m2*100 + d1) {
        while (y1*10000 + m1*100 + d1 > y2*10000 + m2*100 + d1) {

            totalTime--;

            if (++d2 > daysfor(m2, y2)) {
                d2 = 1;
                
                if (++m2 > 12) {
                    m2 = 1;
                    y2++;
                }
            }
        }
    }
    else {
        while (y1*10000 + m1*100 + d1 < y2*10000 + m2*100 + d2) {

            totalTime++;

            if (++d1 > daysfor(m1, y1)) {
                d1 = 1;
                
                if (++m1 > 12) { // happy new year
                    m1 = 1;
                    y1++;
                }
            }

            // std::cout << d1 << "/" << m1 << "/" << y1 << std::endl;
        }
    }

    return totalTime;
}

int main() {

    int day1, month1, year1, day2, month2, year2;
    do {
        std::cin >> day1 >> month1 >> year1;
    } while (!isValid(day1, month1, year1));

    do {
        std::cin >> day2 >> month2 >> year2;
    } while (!isValid(day2, month2, year2) || datecmp(day1, month1, year1, day2, month2, year2) < 0);

    std::cout << "time difference: " << datecmp(day1, month1, year1, day2, month2, year2) << " days"; 

}