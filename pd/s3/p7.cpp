#include <iostream>
#include <vector>

// This function is not needed for the program, it's here merely
// for presentation purposes

void sort(std::vector<int>& argz) { 

    while ([&](){
        
        bool isSorted = true;
        for (int i = 0; i < argz.size() - 1; i++) {
            if (argz[i] > argz[i+1]) {
                std::swap(argz[i], argz[i+1]);
                isSorted = false;
            }
        }

        return !isSorted;

    }()) {}

}

int main() {

    int m, n;
    std::vector<int> A, B;

    std::cin >> m >> n;
    
    while (m--) {
        int i;
        std::cin >> i;
        A.push_back(i);
    }
    
    while (n--) {
        int i;
        std::cin >> i;
        B.push_back(i);
    }

    std::vector<int> AnB, AuB, AdB;

    for (int b : B) { 
        AuB.push_back(b);
    }

    

    for (int a : A) {
        bool isInB = false;
        for (int b : B) {
            if (a == b) {
                AnB.push_back(a);

                isInB = true;
                break;
            }
        }

        if (!isInB) {
            AdB.push_back(a);
            AuB.push_back(a);
        }
    }

    sort(AuB);
    sort(AnB);
    sort(AdB);

    std::cout << std::endl << std::endl;

    std::cout << "AnB = { ";
    for (int i = 0; i < AnB.size(); i++) {
        std::cout << AnB[i] << ((i == AnB.size() - 1) ? " " : ", ");
    }
    std::cout << "}" << std::endl;
    
    std::cout << "AuB = { ";
    for (int i = 0; i < AuB.size(); i++) {
        std::cout << AuB[i] << ((i == AuB.size() - 1) ? " " : ", ");
    }
    std::cout << "}" << std::endl;
    
    std::cout << "A-B = { ";
    for (int i = 0; i < AdB.size(); i++) {
        std::cout << AdB[i] << ((i == AdB.size() - 1) ? " " : ", ");
    }
    std::cout << "}" << std::endl;

    return 0;
}