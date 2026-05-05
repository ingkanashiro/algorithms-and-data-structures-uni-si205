#include <iostream>

int main() {

    int m, n;
    std::cin >> m >> n;

    int A[m], B[n];
    for (int i = 0; i < m; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> B[i];
    }

    int AxiorB[m+n], dist = 0;
    for (int i = 0; i < (m > n ? m : n); i++) {

        if (i < m && i < n) {

            int a = A[i], b = B[i];
            if (a != b) {
                AxiorB[dist] = a;  dist++;
                AxiorB[dist] = b;  dist++;
            }

            continue;
        }
        
        int val = (i < m ? A[i] : B[i]); 
        dist++;
    }

    std::cout << "dist: " << dist << std::endl;
    
    return 0;
}