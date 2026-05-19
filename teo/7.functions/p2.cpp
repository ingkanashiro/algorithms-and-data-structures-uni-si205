#include <iostream>
#include <cstring>

typedef char string[64];

int getWordCountExc(string arg) {

    string words[64];
    for (int j = 0; j < 64; j++) {
        strcpy(words[j], "");
    }
    
    int i = 0, j = 0;
    string thisWord;

    for (int c = 0; c < strlen(arg); c++) {
        
        if (arg[c] != ' ' && c != strlen(arg)-1) {
            thisWord[j] = arg[c];
        }
        else {
            thisWord[j] = 0;

            // check if exists
            bool isAlreadyCounted = false;
            for (int k = 0; k < i; k++) {
                if (!strcmp(words[k], thisWord)) {
                    isAlreadyCounted = true;
                    break;
                }
            }

            if (!isAlreadyCounted) {
                strcpy(words[i], thisWord);
                strcpy(thisWord, "");
                i++;
            }

            j = -1;
        }

        j++;
    }

    return i;
}

int main() {

    string str;
    int wordCount = 0;

    gets(str);
    std::cout << str << std::endl;
    std::cout << "w: " << getWordCountExc(str);

    return 0;
}