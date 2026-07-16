#include <iostream>

bool isleap(int yy) {

    if (yy % 4 == 0) {
        if (yy % 100 == 0 && yy % 400 != 0) {
            return false;
        }

        return true;
    }

    return false;
}

int daysfor(int mm, int yy) {

    if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 10 || mm == 12) {
        return 31;
    }
    else if (mm == 2) {
        return 28 + (isleap(yy) ? 1 : 0);
    }
    else {
        return 30;
    }

}

void dateadv(int &dd, int &mm, int &yy) {

    dd++;
    if (dd > daysfor(mm, yy)) {
        dd = 1;
        mm++;

        if (mm > 12) {
            mm = 0;
            yy++;
        }
    }
}

int datecmp(int d1, int m1, int y1, int d2, int m2, int y2) {

    // make sure DATE1 is before DATE2
    int sgn = 1;

    if ((d1 + 100*m1 + 10000*y1) > (d2 + 100*m2 + 10000*y2)) {
        std::swap(d1, d2);
        std::swap(m1, m2);
        std::swap(y1, y2);

        sgn = -1;
    }

    // figure out distance
    int distance = 0;

    while ((d1 + 100*m1 + 10000*y1) < (d2 + 100*m2 + 10000*y2)) {
        distance++;
        dateadv(d1, m1, y1);
    }

    return distance;
}

int main() {

    int d1, m1, y1, d2, m2, y2;
    
    std::cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
    int dist = datecmp(d1, m2, y1, d2, m2, y2);

    std::cout << "distancia: " << dist << " dd";

    return 0;
}