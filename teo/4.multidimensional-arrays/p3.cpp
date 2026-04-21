/*
    Example 3.
    Store, for a number of students, N, their courses with their means. We shall store up to 40 students and up to 8 courses for each student.

    Input:
        An integer, the number of students, N.
        Then, for every student, an integer, the number of courses, k, for that student and then, in k lines, an integer for the course code and a double
        for the mean of the course.

    Output:
        The most failed course, along side its number of failed.
*/

#include <iostream>

int main() {

    int N;
    do { std::cin >> N; } while (N < 0 || N > 40);

    int numOfCourses[N], codes[N][8];
    double means[N][8];

    for (int t = 0; t < N; t++) {

        do { std::cin >> numOfCourses[t]; } while (numOfCourses[t] > 8 || numOfCourses[t] < 1);

        for (int k = 0; k < numOfCourses[t]; k++) {
            std::cin >> codes[t][k];
            do { std::cin >> means[t][k]; } while (means[t][k] < 0 || means[t][k] > 20);
        }

    }

    int numFailed[N];

    for (int t = 0; t < N; t++) {
        numFailed[t] = 0;
        for (int k = 0; k < numOfCourses[t]; k++) {
            numFailed[t] += (means[t][k] < 10);
        }
    }


    return 0;
}