#include <iostream>

struct student {
    int code;
    float avg;
};

int main() {

    int *p1;
    float *p2;
    student *p3;

    p1 = new(int);
    p2 = new(float);
    p3 = new(student);

    *p1 = 45;
    *p2 = 27.56f;
    p3->code = 111;
    p3->avg = 11.7;

    std::cout << *p1 << " (" << p1 << ")" << std::endl;
    std::cout << *p2 << " (" << p2 << ")" << std::endl;
    std::cout << p3->code << '\t' << p3->avg << " (" << p3 << ")";

    return 0;
}