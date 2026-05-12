#include <iostream>

struct Party {

    char id;
    int votes;
    double perc;
    int senators;
};

int main() {

    int n;
    std::cin >> n;

    Party parties[n];

    int totalVotes = 0;

    for (int i = 0; i < n; i++) {
        parties[i].id = 'A' + i;

        do { std::cin >> parties[i].votes; } while (parties[i].votes < 0);
        totalVotes += parties[i].votes;
    }

    // input:
    // 6
    // 2000 500 3000 7300 800 4200

    // print
    std::cout << std::endl;
    std::cout << "\tVotos" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << parties[i].id << "\t" << parties[i].votes << std::endl;
    }

    // bubble sort
    for (int i = 0; i < n; i++) for (int j = 0; j < n-1; j++) {
        if (parties[j].votes < parties[j+1].votes) {
            Party p = parties[j+1];

            parties[j+1] = parties[j];
            parties[j] = p;
        }
    }

    int t = 0;
    for (int i = 0; i < n; i++) {
        parties[i].perc = (100.0 * parties[i].votes) / totalVotes;

        if (parties[i].perc >= 5) {
            t++;
        }
    }

    // print
    std::cout << std::endl;
    std::cout << "\tVotos\t\tPorcentage" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << parties[i].id << "\t" << parties[i].votes << "\t\t" << parties[i].perc << "%" << std::endl;
    }

    // add to a new array
    Party topParties[t];

    int r = 0;
    for (int i = 0; i < n; i++) {
        if (parties[i].perc >= 5) {
            topParties[r++] = parties[i];
        }
    }

    int voteDistributionDiv[10*t], distributor;

    r = 0;

    // print
    std::cout << std::endl;
    std::cout << "\t\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10" << std::endl;
    
    for (int i = 0; i < t; i++) {
        
        std::cout << topParties[i].id << "\t" << topParties[i].votes << "\t";
        
        for (int j = 0; j < 10; j++) {
            voteDistributionDiv[r] = topParties[i].votes / (j+1);
            std::cout << voteDistributionDiv[r++] << '\t';
        }

        std::cout << std::endl;
    }

    // bubble sort
    for (int i = 0; i < 10*t; i++) for (int j = 0; j < 10*t - 1; j++) {
        if (voteDistributionDiv[j] < voteDistributionDiv[j+1]) {
            int T = voteDistributionDiv[j+1];
            voteDistributionDiv[j+1] = voteDistributionDiv[j];
            voteDistributionDiv[j] = T;
        }
    }

    distributor = voteDistributionDiv[9];

    std::cout << std::endl << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << voteDistributionDiv[i] << '\t';
    }

    for (int i = 0; i < t; i++) {
        topParties[i].senators = (topParties[i].votes / distributor);
    }

    // print
    std::cout << std::endl << std::endl;
    std::cout << "\tVotos\t\tCifra Rep.\tCurules" << std::endl;
    for (int i = 0; i < t; i++) {
        std::cout << topParties[i].id << "\t" << topParties[i].votes << "\t\t" << distributor << "\t\t" << topParties[i].senators << std::endl;
    }

    return 0;
}