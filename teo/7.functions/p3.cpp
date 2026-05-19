#include <iostream>

typedef char string30[30];

struct Student {
    int code;
    string30 name;
    double avg;
};


void swap(Student& a, Student& b) {
    Student tmp = a;
    a = b;
    b = tmp;
}

void sort(Student s[], int n) {
        
    for (int i = 0; i < n; i++) for (int j = 0; j < n-1; j++) {
        if (s[j].avg < s[j+1].avg) {
            swap(s[j], s[j+1]);
        }
    }
}

void podium(Student s[], int n) {
    sort(s, n);

    Student top[4] = {
        s[0], s[1], s[2], s[3]
    };

    int p = (n < 4) ? n : 4;

    std::cout << "\tCode\tName\t\tAverage" << std::endl;
    for (int i = 0; i < p; i++) {
        std::cout << i+1 << ".\t" << s[i].code << '\t' << s[i].name << "\t\t" << s[i].avg << std::endl;      
    }
}


int main() {

    int n;
    do { std::cin >> n; } while (n < 1);

    Student students[n];
    for (int i = 0; i < n; i++) {
        do { std::cin >> students[i].code; } while (students[i].code < 100 || students[i].code > 999);
        fflush(stdin); gets(students[i].name);
        do { std::cin >> students[i].avg; } while (students[i].avg < 0 || students[i].avg > 20);
    }

    podium(students, n);

    return 0;
}