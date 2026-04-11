#include <iostream>

int main() {

    int population;
    std::cin >> population;

    int votesA = 0, votesB = 0, votesC = 0, votesD = 0;

    int t = population;
    while (t--) {

        char c;
        std::cin >> c;

        switch (c) {
            case 'A':
                votesA++;
                break;

            case 'B':
                votesB++;
                break;

            case 'C':
                votesC++;
                break;

            case 'D':
                votesD++;
                break;
        }
    }

    int votes = votesA + votesB + votesC + votesD;
    char fav1 = 'A';

    int mostVotes = votesA;
    if (votesB > mostVotes) {
        mostVotes = votesB;
        fav1 = 'B';
    }
    
    if (votesC > mostVotes) {
        mostVotes = votesC;
        fav1 = 'C';
    }
    
    if (votesD > mostVotes) {
        mostVotes = votesD;
        fav1 = 'D';
    }

    char winner;
    
    if (2 * mostVotes > votes) {
        winner = fav1;
    }
    else {

        char fav2;
        int v = (fav1 == 'A' ? votesB : votesA);
        if (votesB > v && fav1 != 'B') {
            v = votesB;
            fav2 = 'B';
        }
        
        if (votesC > v && fav1 != 'C') {
            v = votesC;
            fav2 = 'C';
        }
        
        if (votesD > v && fav1 != 'D') {
            v = votesD;
            fav2 = 'D';
        }

        // Second round
        std::cout << "Second round triggered! (" << fav1 << " vs " << fav2 << ")" << std::endl;
        
        int votesFav1 = 0, votesFav2 = 0;
        
        t = population;
        while (t--) {

            char c;
            std::cin >> c;

            if (c == fav1) {
                votesFav1++;
                continue;
            }

            if (c == fav2) {
                votesFav2++;
                continue;
            }

            // Null vote.
        }

        if (votesFav1 > votesFav2) {
            winner = fav1;
        }
        else if (votesFav1 < votesFav2) {
            winner = fav2;
        }
        else {
            throw std::runtime_error("could not resolve draw after voting");
        }
    }

    std::cout << winner << std::endl;

    return 0;
}