#include <iostream>
#include <cstring>

typedef char string[100];
typedef char sstring[50];

struct book {
    int code;
    string title;
    sstring author;
};

int getlen(book L, int i) {
    if (L.title[i] == 0) {
        return i;
    }
    
    return getlen(L, ++i);
}

int main() {

    int n;
    std::cin >> n;

    book lib[n];
    for (int i = 0; i < n; i++) {
        std::cout << std::endl;
        
        do { std::cin >> lib[i].code; } while (lib[i].code < 1000000 || lib[i].code > 9999999);
        
        string title; sstring author;

        fflush(stdin);
        gets(title);
        
        fflush(stdin);
        gets(author);

        strcpy(lib[i].title, title);
        strcpy(lib[i].author, author);
    }

    int len[n];
    for (int i = 0; i < n; i++) {
        len[i] = getlen(lib[i], 0);
    }

    // sort books by indexation
    int index[n];
    for (int i = 0; i < n; i++) {
        index[i] = i;
    }

    for (int i = 0; i < n; i++) for (int j = 0; j < n-1; j++) {
        if (len[index[j]] < len[index[j+1]]) {
            int t = len[index[j]];
            len[index[j]] = len[index[j+1]];
            len[index[j+1]] = t;
        }
    }

    // print all books with the highest title length
    std::cout << "Resultado:" << std::endl;
    for (int i : index) {
        if (len[i] == len[0]) {
            std::cout << lib[i].code << "\t\t" << lib[i].title << "\t\t" << lib[i].author << "\t\t" << len[i] << " caracteres" << std::endl;
        }
        else break;
    }

    return 0;
}