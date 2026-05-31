#include <iostream>
#include <cstring>

typedef char string[64];

int addup(int dest, string str, int i, int s) {
    
    if (i < strlen(str)) {

        if (str[i] >= '0' && str[i] <= '9') {
            int v = (str[i] - '0');
            return addup(dest, str, ++i, 10*s + v);
        }
        else {
            return addup(dest + s, str, ++i, 0);
        }

    }

    return (dest + s);
}

int main() {

    string str;
    fflush(stdin);
    gets(str);

    fflush(stdin);

    int sum = addup(0, str, 0, 0);
    std::cout << sum << std::endl;

    return 0;
}