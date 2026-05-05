#include <iostream>

int main() {

    int rank_U[33], rank_V[33], rank_W[33];
    int codes_U[33], codes_V[33], codes_W[33];
    double avg_U[33], avg_V[33], avg_W[33];

    int nU, nV, nW;

    for (int i = 0; i < 33; i++) {
        rank_U[i] = -1;
        rank_V[i] = -1;
        rank_W[i] = -1;
    }

    std::cin >> nU >> nV >> nW;

    // Insertion sort
    for (int i = 0; i < nU; i++) {

        do { std::cin >> codes_U[i]; } while (codes_U[i] < 100 || codes_U[i] > 999);
        do { std::cin >> avg_U[i]; } while (avg_U[i] < 0 || avg_U[i] > 20);
        
        if (i == 0) {
            rank_U[i] = i;
            continue;
        }

        int j = 0;
        while (j < i) {

            if (avg_U[i] > avg_U[rank_U[j]]) {

                for (int r = i; r > j; r--) {
                    rank_U[r] = rank_U[r-1];
                }

                rank_U[j] = i;
                break;
            }

            if (++j == i) {
                rank_U[j] = i;
            }
        }
    }

    for (int i = 0; i < nV; i++) {

        do { std::cin >> codes_V[i]; } while (codes_V[i] < 100 || codes_V[i] > 999);
        do { std::cin >> avg_V[i]; } while (avg_V[i] < 0 || avg_V[i] > 20);
        
        if (i == 0) {
            rank_V[i] = i;
            continue;
        }

        int j = 0;
        while (j < i) {

            if (avg_V[i] > avg_V[rank_V[j]]) {

                for (int r = i; r > j; r--) {
                    rank_V[r] = rank_V[r-1];
                }

                rank_V[j] = i;
                break;
            }

            if (++j == i) {
                rank_V[j] = i;
            }
        }
    }

    for (int i = 0; i < nW; i++) {

        do { std::cin >> codes_W[i]; } while (codes_W[i] < 100 || codes_W[i] > 999);
        do { std::cin >> avg_W[i]; } while (avg_W[i] < 0 || avg_W[i] > 20);
        
        if (i == 0) {
            rank_W[i] = i;
            continue;
        }

        int j = 0;
        while (j < i) {

            if (avg_W[i] > avg_W[rank_W[j]]) {

                for (int r = i; r > j; r--) {
                    rank_W[r] = rank_W[r-1];
                }

                rank_W[j] = i;
                break;
            }

            if (++j == i) {
                rank_W[j] = i;
            }
        }
    }
    
    // Print top 3 for each section:
    std::cout << "section: U" << std::endl;
    if (nU > 0) { std::cout << "      1: " << codes_U[rank_U[0]] << '\t' << avg_U[rank_U[0]] << std::endl; }
    if (nU > 1) { std::cout << "      2: " << codes_U[rank_U[1]] << '\t' << avg_U[rank_U[1]] << std::endl; }
    if (nU > 2) { std::cout << "      3: " << codes_U[rank_U[2]] << '\t' << avg_U[rank_U[2]] << std::endl; }
  
    std::cout << "section: V" << std::endl;
    if (nV > 0) { std::cout << "      1: " << codes_V[rank_V[0]] << '\t' << avg_V[rank_V[0]] << std::endl; }
    if (nV > 1) { std::cout << "      2: " << codes_V[rank_V[1]] << '\t' << avg_V[rank_V[1]] << std::endl; }
    if (nV > 2) { std::cout << "      3: " << codes_V[rank_V[2]] << '\t' << avg_V[rank_V[2]] << std::endl; }
 
    std::cout << "section: W" << std::endl;
    if (nW > 0) { std::cout << "      1: " << codes_W[rank_W[0]] << '\t' << avg_W[rank_W[0]] << std::endl; }
    if (nW > 1) { std::cout << "      2: " << codes_W[rank_W[1]] << '\t' << avg_W[rank_W[1]] << std::endl; }
    if (nW > 2) { std::cout << "      3: " << codes_W[rank_W[2]] << '\t' << avg_W[rank_W[2]] << std::endl; }

    return 0;
}