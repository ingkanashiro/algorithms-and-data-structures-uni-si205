#include <iostream>
#include <cstring>

typedef char string[64];

void cleanse(string out, string in, int& s, int& d, int p[]) {

    int j = 0; s = 0; d = 0;
    for (int i = 0; i < strlen(in); i++) {

        if (i == 0 && in[i] == ' ') {   // special case for trailing spaces
            p[0] = 0; s++;
            continue;
        }

        if (in[i-1] == ' ' && in[i] == ' ') {
            p[s+d] = i; s++;
            continue;
        }

        if (in[i] >= '0' && in[i] <= '9') {
            p[s+d] = i; d++;
            continue;
        }

        out[j] = in[i]; 
        j++;

        if (i == strlen(in) - 1) {
            out[j] = 0;    
        }
    }
}

int main() {

    string str;
    fflush(stdin);
    gets(str);

    int spaces; int digits;
    int positions[strlen(str)];

    std::cout << std::endl;
    for (int i = 0; i < strlen(str); i++) {
        std::cout << str[i] << "  ";
    }
    
    std::cout << std::endl;
    for (int i = 0; i < strlen(str); i++) {
        std::cout << i << ((i < 10) ? "  " : " ");
    }

    std::cout << std::endl << std::endl;
    
    string cstr;
    cleanse(cstr, str, spaces, digits, positions);

    std::cout << "cleansed text: " << cstr << std::endl;
    std::cout << "\tommited spaces: " << spaces << std::endl;
    std::cout << "\tommited digits: " << digits << std::endl;
    std::cout << "\tpositions ommited: ";
    for (int k = 0; k < spaces + digits; k++) {
        std::cout << positions[k] << " ";
    }

    return 0;
}