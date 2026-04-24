/*
    Example 4.
    Enter two sets A, B, and then determine their union and intersection.
    Don't add repeated elements to the sets.
*/

#include <iostream>

int main() {

    int cardinalA, cardinalB;
    
    do { std::cin >> cardinalA; } while (cardinalA <= 0);
    int setA[cardinalA];

    for (int i = 0; i < cardinalA; i++) {
        
        int k; std::cin >> k;

        bool alreadyInSet = false;
        for (int j = 0; j < i; j++) {
            if (k == setA[j]) {
                alreadyInSet = true;
                break;
            }
        }

        if (alreadyInSet) {
            i--;
            continue;
        }

        // setA[i] = k;

        // Insertion sort
        if (i == 0) {
            setA[i] = k;
            continue;
        }

        int j = 0;
        while (j < i) {

            if (k < setA[j]) {

                for (int r = i; r > j; r--) {
                    setA[r] = setA[r-1];
                }

                setA[j] = k;
                break;
            }


            if (++j == i) {
                setA[j] = k;
            }
        }
    }
    
    do { std::cin >> cardinalB; } while (cardinalB <= 0);
    int setB[cardinalB];

    for (int i = 0; i < cardinalB; i++) {
        
        int k; std::cin >> k;

        bool alreadyInSet = false;
        for (int j = 0; j < i; j++) {
            if (k == setB[j]) {
                alreadyInSet = true;
                break;
            }
        }

        if (alreadyInSet) {
            i--;
            continue;
        }

        setB[i] = k;

        if (i == 0) {
            setB[i] = k;
            continue;
        }

        int j = 0;
        while (j < i) {

            if (k < setB[j]) {

                for (int r = i; r > j; r--) {
                    setB[r] = setB[r-1];
                }

                setB[j] = k;
                break;
            }


            if (++j == i) {
                setB[j] = k;
            }
        }
    }

    std::cout << std::endl << "A = {";
    for (int i = 0; i < cardinalA; i++) {
        std::cout << setA[i] << (i == cardinalA - 1 ? "}" : ", ");
    }
    std::cout << std::endl;

    std::cout << "B = {";
    for (int i = 0; i < cardinalB; i++) {
        std::cout << setB[i] << (i == cardinalB - 1 ? "}" : ", ");
    }
    std::cout << std::endl << std::endl;

    int cardinalAnB = 0, cardinalAuB = cardinalA;

    for (int b : setB) {
        
        bool isCommon = false;
        for (int a : setA) {
            if (a == b) {
                isCommon = true;
                break;
            }
        }

        cardinalAnB += isCommon;
        cardinalAuB += (!isCommon);
    }

    int setAuB[cardinalAuB], setAnB[cardinalAnB];

    for (int i = 0; i < cardinalA; i++) {
        setAuB[i] = setA[i];
    }

    int bi = 0;
    for (int i = 0; i < cardinalAnB; i++) {

        int b = setB[bi];
            
        bool isCommon = false;
        for (int a : setA) {
            if (a == b) {
                isCommon = true;
                break;
            }
        }

        bi++;

        if (!isCommon) {
            i--;
            continue;
        }

        if (i == 0) {
            setAnB[i] = b;
            continue;
        }

        int j = 0;
        while (j < i) {

            if (b < setAnB[j]) {

                for (int r = i; r > j; r--) {
                    setAnB[r] = setAnB[r-1];
                }
                setAnB[j] = b;
            }

            if (++j == i) {
                setAnB[j] = b;
            }
        }
    }

    bi = 0;
    for (int i = cardinalA; i < cardinalAuB; i++) {

        int b = setB[bi];
            
        bool isCommon = false;
        for (int a : setA) {
            if (a == b) {
                isCommon = true;
                break;
            }
        }

        bi++;

        if (isCommon) {
            i--;
            continue;
        }

        if (i == 0) {
            setAuB[i] = b;
            continue;
        }

        int j = 0;
        while (j < i) {

            if (b < setAuB[j]) {

                for (int r = i; r > j; r--) {
                    setAuB[r] = setAuB[r-1];
                }
                setAuB[j] = b;
            }

            if (++j == i) {
                setAuB[j] = b;
            }
        }
    }

    

    std::cout << std::endl << "AuB = {";
    for (int i = 0; i < cardinalAuB; i++) {
        std::cout << setAuB[i] << (i == cardinalAuB - 1 ? "}" : ", ");
    }
    std::cout << std::endl;

    std::cout << "AnB = {";
    for (int i = 0; i < cardinalAnB; i++) {
        std::cout << setAnB[i] << (i == cardinalAnB - 1 ? "}" : ", ");
    }
    std::cout << std::endl << std::endl;

    return 0;
}