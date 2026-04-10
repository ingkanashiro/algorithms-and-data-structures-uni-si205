#include <iostream>
#include <vector>
#include <array>

using namespace std;

struct date {
    int day;
    int month;
    int year;
};

bool isValidDate(date arg) {

    const int MAX_DAY_FOR_MONTH[12] = {
        31, ((arg.year % 4 == 0 && arg.year % 400 != 0) ? 29 : 28), 31, 30, 31, 30, 31, 30, 30, 31, 30, 31
    };

    return (arg.month < 13 && arg.month > 0 && arg.day > 0 && arg.day < MAX_DAY_FOR_MONTH[arg.month - 1] && arg.year > 0);
}

date to_date(string arg) {
    
    string k = "";
    vector<int> array;
    for (char c : arg) {

        if (c == '.' || c == '/') {
            
            array.push_back(stoi(k));        
            
            k = "";
            continue;
        }

        k += c;
    }

    if (k.length() == 2) {
        string add = ((stoi(k) > 5) ? "19" : "20");
        k = add + k;
    }

    array.push_back(stoi(k));

    date d;
    d.day = array[0];
    d.month = array[1];
    d.year = array[2];
    
    return d;
}

int min(vector<int> list)
{

    int x = list[0];

    for (int l : list)
    {
        if (l < x)
        {
            x = l;
        }
    }

    return x;
}


int main() {

    date birth1, birth2, birth3;
    string str1, str2, str3;

    cin >> str1 >> str2 >> str3;

    birth1 = to_date(str1);
    birth2 = to_date(str2);
    birth3 = to_date(str3);

    if (!isValidDate(birth1) || !isValidDate(birth2) || !isValidDate(birth3)) {
        throw runtime_error("syntax error.");
    }

    int age1, age2, age3;   // as of 13/10/2005

    age1 = 2005 - birth1.year - ((birth1.month > 10) || (birth1.month == 10 && birth1.day > 13));
    age2 = 2005 - birth2.year - ((birth2.month > 10) || (birth2.month == 10 && birth2.day > 13));
    age3 = 2005 - birth3.year - ((birth3.month > 10) || (birth3.month == 10 && birth3.day > 13));

    int youngest = min({age1, age2, age3});

    cout << "youngest: " << youngest << endl;

    return 0;
}