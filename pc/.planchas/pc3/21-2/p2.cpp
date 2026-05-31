#include <iostream>
#include <cstring>

typedef char string[30];

struct student {

    string lastName;
    int code;
};

struct course {

    string name;
    int student;

    double scores[3];
};

double avg(double x[]) {
    double scoreAcc = x[0] + x[1] + x[2];
    
    double min = x[0];
    if (x[1] < min) {
        min = x[1];
    }
    if (x[2] < min) {
        min = x[2];
    }

    scoreAcc -= min;
    scoreAcc /= 2;

    return scoreAcc;
}

int main() {

    int n;
    std::cin >> n;

    student list[n];
    int numOfCourses[n];
    course courses[n][8];

    for (int i = 0; i < n; i++) {

        do { std::cin >> list[i].code; } while (list[i].code < 1000 || list[i].code > 9999);
        
        fflush(stdin);
        gets(list[i].lastName);

        do { std::cin >> numOfCourses[i]; } while (numOfCourses[i] < 1 || numOfCourses[i] > 8);

        for (int j = 0; j < numOfCourses[i]; j++) {

            std::cout << std::endl;

            fflush(stdin);
            gets(courses[i][j].name);

            for (int k = 0; k < 3; k++) {
                do { std::cin >> courses[i][j].scores[k]; } while (courses[i][j].scores[k] < 0 || courses[i][j].scores[k] > 20);
            }
        }
        
        std::cout << "--" << std::endl;
    }

    int index[n];
    for (int i = 0; i < n; i++) {
        index[i] = i;
    }

    for (int i = 0; i < n; i++) for (int j = 0; j < n-1; j++) {
        if (list[index[j]].code > list[index[j+1]].code) {
            std::swap(index[j], index[j+1]);
        }
    }

    // Aprobado desde 10
    std::cout << "CÓDIGO\t\tAPELLIDOS\t\tCURSO\t\tN1\tN2\tN3\tPROM\tOBSERVACIÓN" << std::endl;
    for (int i : index) for (int j = 0; j < numOfCourses[i]; j++) {
        if (j == 0) { 
            std::cout << list[i].code << "\t\t" << list[i].lastName << "\t\t";
        }
        else {
            std::cout << "\t\t\t\t\t";
        }
        
        std::cout << courses[i][j].name << "\t" << courses[i][j].scores[0] << '\t' << courses[i][j].scores[1] << '\t' << courses[i][j].scores[2]
            << "\t" << avg(courses[i][j].scores) << '\t' << ((avg(courses[i][j].scores) < 10) ? "Desaprobado" : "Aprobado") << std::endl;
    }


    return 0;
}