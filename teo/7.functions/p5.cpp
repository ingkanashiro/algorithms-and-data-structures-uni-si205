#include <iostream>
#include <cstring>

typedef char string[256];
typedef char sstring[32];

bool isPalindrome(sstring s) {
    sstring z;
    strcpy(z, s);
    return (strcmpi(strrev(z), s) == 0);
}

int getPalindromes(sstring out[], string in) {
    
    sstring word = ""; int j = 0, k = 0;

    for (int i = 0; i < strlen(in); i++) {

        if (in[i] == ' ' || i == strlen(in) - 1) {
            if (i == strlen(in) - 1) {
                word[k++] = in[i];
            }
            word[k] = '\000';

            if (isPalindrome(word)) {
                strcpy(out[j++], word);
            }

            strcpy(word, "");
            k = 0;
        }
        else {
            word[k++] = in[i];
        }
    }

    return j;
}

int main() {

    string str;
    gets(str);

    sstring palindromes[32];
    int numOfPalindromes = getPalindromes(palindromes, str);
    
    std::cout << "palindromes found: " << numOfPalindromes << std::endl;
    for (int i = 0; i < numOfPalindromes; i++) {
        std::cout << "- " << palindromes[i] << std::endl;
    }

    return 0;
}