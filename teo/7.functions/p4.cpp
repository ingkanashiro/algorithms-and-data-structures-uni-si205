#include <iostream>
#include <cstring>

typedef char string[128];

void cin(int s[], int n) {
    for (int i = 0; i < n; i++) {

        int input;
        bool alreadyAdded = false;

        do {
            std::cin >> input;
            
            alreadyAdded = false;
            for (int j = 0; j < i; j++) {
                if (s[j] == input) {
                    alreadyAdded = true;
                    break;
                }
            }
        } while (alreadyAdded);
        
        if (i == 0) {
            s[i] = input;
            continue;
        }



        int j = 0;
        while (j < i) {

            if (input < s[j]) {

                for (int r = i; r > j; r--) {
                    s[r] = s[r-1];
                }

                s[j] = input;
                break;
            }

            if (++j == i) {
                s[j] = input;
            }
        }
    }
}

void sort(int s[], int n) {
    for (int i = 0; i < n; i++) for (int j = 0; j < n-1; j++) {
        if (s[j] > s[j+1]) {
            std::swap(s[j], s[j+1]);
        }
    }
}

void print(int s[], int n, string label) {
    std::cout << std::endl << label << " = { ";
    for (int i = 0; i < n; i++) {
        std::cout << s[i] << ((i == n-1) ? " }" : ", "); 
    }
}

void setunion(int dest[], int a[], int m, int b[], int n, int& c) {
    c = 0;

    for (int i = 0; i < m; i++) {
        dest[c] = a[i];
        c++;
    }

    for (int i = 0; i < n; i++) {
        bool alreadyAdded = false;
        for (int j = 0; j < m; j++) {
            if (a[j] == b[i]) {
                alreadyAdded = true;
                break;
            }
        }

        if (!alreadyAdded) {
            dest[c] = b[i];
            c++;
        }
    }

    sort(dest, c);
}

void setintersect(int dest[], int a[], int m, int b[], int n, int& c) {
    c = 0;

    for (int i = 0; i < n; i++) {
        bool isCommon = false;
        for (int j = 0; j < m; j++) {
            if (a[j] == b[i]) {
                isCommon = true;
                break;
            }
        }

        if (isCommon) {
            dest[c] = b[i];
            c++;
        }
    }

    sort(dest, c);
}

void setdif(int dest[], int a[], int m, int b[], int n, int& c) {
    c = 0;

    for (int i = 0; i < m; i++) {
        bool isCommon = false;
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                isCommon = true;
                break;
            }
        }

        if (!isCommon) {
            dest[c] = a[i];
            c++;
        }
    }

    // there's no need to sort as inputs are already ordered, but sure, why not.
    sort(dest, c);
}

int main() {

    int m, n;
    do { std::cin >> m; } while (m < 1 || m > 20);
    do { std::cin >> n; } while (n < 1 || n > 20);

    int A[m], B[n];
    cin(A, m); cin(B, n);

    string instruction;
    string keywords[32];

    for (int i = 0; i < 32; i++) {
        strcpy(keywords[i], "");
    }

    // find every keyword inside instruction string
    gets(instruction);
    
    string c; int k = 0; int q = 0;
    for (int i = 0; i < strlen(instruction); i++) {
        if (instruction[i] == ' ') {
            
            c[k] = '\000';
            if (!strcmpi(c, "union") || !strcmpi(c, "unión") || !strcmpi(c, "interseccion") || !strcmpi(c, "intersección") || !strcmpi(c, "diferencia")) {
                strcpy(keywords[q], c); 
                q++;
            }
            
            strcpy(c, ""); k = 0;
        }
        else {
            c[k] = instruction[i];
            k++;
        }
        
        if (i == strlen(instruction) - 1) {
            c[k] = '\000';
            if (!strcmpi(c, "union") || !strcmpi(c, "unión") || !strcmpi(c, "interseccion") || !strcmpi(c, "intersección") || !strcmpi(c, "diferencia")) {
                strcpy(keywords[q], c); 
                q++;
            }
            
            strcpy(c, ""); k = 0;
        }
    }

    std::cout << std::endl << "in:";
    print(A, m, "A"); print(B, n, "B");
    
    std::cout << std::endl << std::endl << "out:";

    for (int i = 0; i < 32; i++) {
        if (!strcmp(keywords[i], "")) break;

        if (!strcmpi(keywords[i], "union") || !strcmpi(keywords[i], "unión")) {
            int AuB[m+n]; int c_AuB;
            setunion(AuB, A, m, B, n, c_AuB);

            print(AuB, c_AuB, "AuB");
        }

        if (!strcmpi(keywords[i], "interseccion") || !strcmpi(keywords[i], "intersección")) {
            int AnB[std::min(m, n)]; int c_AnB;
            setintersect(AnB, A, m, B, n, c_AnB);

            print(AnB, c_AnB, "AnB");
        }

        if (!strcmpi(keywords[i], "diferencia")) {
            int AdB[m]; int c_AdB;
            setdif(AdB, A, m, B, n, c_AdB);

            print(AdB, c_AdB, "A-B");
        }
    }

    return 0;
}