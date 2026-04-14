#include <iostream>

// decrec. año, crec. mes, decrec. día
int main() {

    int n;
    std::cin >> n;

    int dates[n][3]; // {d, m, y} ----> INPUT: dd mm yyyy

    // Insertion sort
    for (int i = 0; i < n; i++) {
        int dd, mm, yy;
        std::cin >> dd >> mm >> yy;

        if (i == 0) {
            dates[0][0] = dd;
            dates[0][1] = mm;
            dates[0][2] = yy;

            continue;
        }

        int j = 0;
        while (j < i) { // 0 1 2 3 5 

            if (yy > (dates[j])[2]) {

                for (int r = i; r > j; r--) {
                    dates[r][0] = dates[r-1][0];
                    dates[r][1] = dates[r-1][1];
                    dates[r][2] = dates[r-1][2];
                }

                dates[j][0] = dd;
                dates[j][1] = mm;
                dates[j][2] = yy;

                break;
            }
            else if (yy == (dates[j])[2]) {
                if (mm < (dates[j])[1]) {

                    for (int r = i; r > j; r--) {
                        dates[r][0] = dates[r-1][0];
                        dates[r][1] = dates[r-1][1];
                        dates[r][2] = dates[r-1][2];
                    }

                    dates[j][0] = dd;
                    dates[j][1] = mm;
                    dates[j][2] = yy;

                    break;
                }
                else if (mm == (dates[j])[1]) {
                    if (dd > (dates[j])[0]) {

                        for (int r = i; r > j; r--) {
                            dates[r][0] = dates[r-1][0];
                            dates[r][1] = dates[r-1][1];
                            dates[r][2] = dates[r-1][2];
                        }

                        dates[j][0] = dd;
                        dates[j][1] = mm;
                        dates[j][2] = yy;

                        break;
                    }
                }
            }

            if (++j == i) {
                dates[j][0] = dd;
                dates[j][1] = mm;
                dates[j][2] = yy; 
            }
        }
    }

    std::cout << "*** SORTED LIST ***" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << dates[i][0] << "/" << dates[i][1] << "/" << dates[i][2] << std::endl;
    }

    return 0;
}