#include <iostream>
#include <ctime>

int main() {
    srand(time(NULL));

    int n;
    do { std::cin >> n; } while (n < 2 || n > 9);

    int matrix[n][n];

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        matrix[i][j] = rand() % 2;        
    }

    // print
    std::cout << std::endl << std::endl << "matrix:\n  ";
    for (int j = 0; j < n; j++) {
        char node = 'A';
        node += j;

        std::cout << node << " ";
    }
    for (int i = 0; i < n; i++) for (int j = -1; j < n; j++) {
        if (j == -1) {
            char node = 'A';
            node += i;

            std::cout << '\n' << node << " ";
            continue;
        }

        std::cout << matrix[i][j] << " ";
    }

    for (int k = 0; k < n; k++) {
        matrix[k][k] = 1;
    }

    // print
    std::cout << std::endl << std::endl << "add 1s:\n  ";
    for (int j = 0; j < n; j++) {
        char node = 'A';
        node += j;

        std::cout << node << " ";
    }
    for (int i = 0; i < n; i++) for (int j = -1; j < n; j++) {
        if (j == -1) {
            char node = 'A';
            node += i;

            std::cout << '\n' << node << " ";
            continue;
        }

        std::cout << matrix[i][j] << " ";
    }

    // sort rows
    int sort_i[n], counts[n], first[n];
    for (int i = 0; i < n; i++) {

        counts[i] = 0; bool isFirst = true;
        for (int j = 0; j < n; j++) {
            counts[i] += matrix[i][j];
            if (matrix[i][j] && isFirst) {
                isFirst = false;
                first[i] = j;
            }
        }

        // insertion sort
        if (i == 0) {
            sort_i[i] = i;
            continue;
        }

        int j = 0;
        while (j < i) {

            // bool shift = (counts[i] > counts[sort_i[j]] || 
            //     (counts[i] == counts[sort_i[j]] && (first[i] < first[sort_i[j]] || 
            //         (first[i] == first[sort_i[j]] && i > sort_i[j]))));
            
            bool shift = (counts[i] > counts[sort_i[j]]
                || counts[i] == counts[sort_i[j]] && (first[i] > first[sort_i[j]] 
                    || (first[i] == first[sort_i[j]] && i > sort_i[j])));

            if (shift) {
                for (int r = i; r > j; r--) {
                    sort_i[r] = sort_i[r-1];
                }
                sort_i[j] = i; break;
            }

            if (++j == i) {
                sort_i[j] = i;
            }
        }
    }

    int ps_matrix[n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        ps_matrix[i][j] = matrix[sort_i[i]][j];
    }

    // print
    std::cout << std::endl << std::endl << "sort rows:\n  ";
    for (int j = 0; j < n; j++) {
        char node = 'A';
        node += j;

        std::cout << node << " ";
    }
    for (int i = 0; i < n; i++) for (int j = -1; j < n; j++) {
        if (j == -1) {
            char node = 'A';
            node += sort_i[i];

            std::cout << '\n' << node << " ";
            continue;
        }

        std::cout << ps_matrix[i][j] << " ";
    }

    int s_matrix[n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        s_matrix[i][j] = ps_matrix[i][sort_i[j]];
    }

    // print
    std::cout << std::endl << std::endl << "sort columns:\n  ";
    for (int j = 0; j < n; j++) {
        char node = 'A';
        node += sort_i[j];

        std::cout << node << " ";
    }
    for (int i = 0; i < n; i++) for (int j = -1; j < n; j++) {
        if (j == -1) {
            char node = 'A';
            node += sort_i[i];

            std::cout << '\n' << node << " ";
            continue;
        }

        std::cout << s_matrix[i][j] << " ";
    }

    return 0;
}