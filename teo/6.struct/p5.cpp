/*
    Example 6.
    For a list of N student, we wish to store their code (3 digits), a list of their courses, each with a code (3 digits) and a final grade average (up to 10 points).
    Present for each student the number of failed courses and the most failed courses.
*/

#include <iostream>

struct Course {
    int code;
    double avg;
};

struct Student {
    int code;
    double numOfCourses;
    Course courses[10];
};

int main() {

    const double MINIMUM_PASS_NOTE = 5; // ???

    int n;
    do { std::cin >> n; } while (n < 1);

    Student students[n];

    for (int i = 0; i < n; i++) {
        do { std::cin >> students[i].code; } while (students[i].code < 100 || students[i].code > 999);
        do { std::cin >> students[i].numOfCourses; } while (students[i].numOfCourses < 1 || students[i].numOfCourses > 10);

        for (int j = 0; j < students[i].numOfCourses; j++) {
            do { std::cin >> students[i].courses[j].code; } while (students[i].courses[j].code < 100 || students[i].courses[j].code > 999);
            do { std::cin >> students[i].courses[j].avg; } while (students[i].courses[j].avg < 0 || students[i].courses[j].avg > 10);
        }
    }

    // Number of failed courses per student
    for (int i = 0; i < n; i++) {
        int failedCourses = 0;

        for (int j = 0; j < students[i].numOfCourses; j++) {
            if (students[i].courses[j].avg < MINIMUM_PASS_NOTE) {
                failedCourses++;
            }
        }

        std::cout << students[i].code << '\t' << "failed: " << failedCourses << std::endl;
    }

    // Most failed courses
    // Courses have codes ranging from 100 to 999, so we make an array to store the number of failed students per course.

    int failedByCourseCode[900];

    for (int c = 0; c < 900; c++) {
        failedByCourseCode[c] = 0;
    }

    for (int i = 0; i < n; i++) for (int j = 0; j < students[i].numOfCourses; j++) {
        if (students[i].courses[j].avg < MINIMUM_PASS_NOTE) {
            failedByCourseCode[students[i].courses[j].code - 100]++;
        }
    }

    int mostFailedCourses[900];
    for (int c = 0; c < 900; c++) {
        mostFailedCourses[c] = c+100;
    }

    for (int i = 0; i < 900; i++) for (int j = 0; j < 899; j++) {
        if (failedByCourseCode[mostFailedCourses[j]-100] < failedByCourseCode[mostFailedCourses[j+1]-100]) {
            std::swap(mostFailedCourses[j], mostFailedCourses[j+1]);
        }
    }

    std::cout << "Courses ranked by number of failed runs: " << std::endl;
    for (int c = 0; c < 900; c++) {
        std::cout << mostFailedCourses[c] << '\t' << "# failed: " << failedByCourseCode[mostFailedCourses[c]-100] << std::endl;
    }

    return 0;
}