#include <iostream>

int main() {

    // courseData[section][student][index] --> index: 0 (code), 1-8 (scores), 9 (average?)
    int courseData[3][30][10];

    for (int s = 0; s < 3; s++) for (int i = 0; i < 30; i++) for (int x = 0; x < 10; x++) {
        courseData[s][i][x] = -1; // fill all data with impossible values to find when it ends.
    } 

    /*
        INPUT:
        For every section:
            * 1 int for the number of students
            * For every student in the section:
                * 1 int (n) for the number of grades
                * n grades
    */

    for (int s = 0; s < 3; s++) {

        int studentCount;
        do { std::cin >> studentCount; } while (studentCount < 0 || studentCount > 30);

        for (int i = 0; i < studentCount; i++) {
            
            int numOfGrades;
            double avg = 0;

            do { std::cin >> numOfGrades; } while (numOfGrades < 1 || numOfGrades > 8);

            for (int x = 0; x < numOfGrades+1; x++) {
                if (x == 0) {
                    do { std::cin >> courseData[s][i][x]; } while (courseData[s][i][x] < 100 || courseData[s][i][x] > 999); // student code
                    continue;
                }
                do { std::cin >> courseData[s][i][x]; } while (courseData[s][i][x] < 0 || courseData[s][i][x] > 20);
                avg += courseData[s][i][x];
            }

            avg /= numOfGrades;
            if (avg < 6) {
                courseData[s][i][9] = 0;
            }
            else {
                courseData[s][i][9] = 1;
            }
        }
    }

    // Show full array? (this is optional i guess)

    // Show modified array
    for (int s = 0; s < 3; s++) {
        std::cout << "section " << s << ":" << std::endl;
        for (int i = 0; i < 30; i++) {

            // Print students until we hit a -1 (invalid value).
            if (courseData[s][i][0] == -1) {
                break; // jump to next section
            }

            // will only print values if student has average not lower than 6.
            if (courseData[s][i][9]) {
                std::cout << "* ";

                for (int x = 0; x < 9; x++) {
                    if (courseData[s][i][x] == -1) {
                        break; // jump to next student after printing all scores.
                    }

                    std::cout << courseData[s][i][x] << " ";
                }

                std::cout << std::endl;
            }
        }
    }

    return 0;
}