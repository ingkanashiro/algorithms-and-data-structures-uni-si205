#include <iostream>
#include <vector>

using namespace std;

struct person {
    char gender; // M or F
    int age;

    person(char gender, int age) : gender(gender), age(age) {}
};

void sortByAge(vector<person>& argz) {

    // Bubble sort respect of age

    while([argz](){

        bool isSorted = true;

        for (int i = 1; i < argz.size(); i++) {
            if (argz[i - 1].age > argz[i].age) {
                isSorted = false;
                break;
            }
        }

        return !isSorted;

    }()) {

        for (int i = 0; i < argz.size() - 1; i++) {
            if (argz[i].age > argz[i + 1].age) {
                swap(argz[i], argz[i + 1]);
            }
        }
        
    }
}

void reverse(vector<person>& argz) {

    vector<person> rev;

    for (int i = argz.size() - 1; i >= 0; i--) {
        rev.push_back(argz[i]);
    }

    argz = rev;
}

int main() {

    char g1, g2, g3;
    int a1, a2, a3;

    cin >> g1 >> a1 >> g2 >> a2 >> g3 >> a3;

    person person1 = person(g1, a1), 
           person2 = person(g2, a2), 
           person3 = person(g3, a3);

    vector<person> list = {person1, person2, person3};
    sortByAge(list);
    reverse(list);

    for (person p : list) {
        cout << p.age << p.gender << " ";
    }
}

