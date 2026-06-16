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

    std::cout << p1 << " " << p2 << " " << p3 << std::endl;
    
    p1++; p2++; p3++; // move all pointers one position
    
    std::cout << p1 << " " << p2 << " " << p3 << std::endl;


    return 0;
}