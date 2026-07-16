#include <iostream>
#include <cstring>

typedef char string[128];

int seekfor(string target, string objective) {

    string current; int k = 0, n = 0;
    for (int i = 0; i < strlen(objective); i++) {

        // get word
        if (objective[i] == ' ' || objective[i] == '\000') {

            current[k] = 0;
            
            if (strcmpi(target, current) == 0) {
                n++;
            }

            strcpy(current, "");
            k = 0;
        }
        else {
            current[k++] = objective[i];
        }
    }
    
    return n;
}

int main() {

    string input;
    std::cout << "buscar en: "; gets(input); fflush(stdin);

    string word;
    std::cout << "> "; std::cin >> word;

    std::cout << std::endl;
    std::cout << "n: " << seekfor(word, input) << std::endl;

    return 0;
}