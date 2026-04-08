#include <iostream>
#include <vector>

using namespace std;

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

int max(vector<int> list)
{

    int x = list[0];

    for (int l : list)
    {
        if (l > x)
        {
            x = l;
        }
    }

    return x;
}

int main()
{

    int age1, age2, age3, age4;
    cin >> age1 >> age2 >> age3 >> age4;

    cout << "min: " << min({age1, age2, age3, age4}) << endl;
    cout << "max: " << max({age1, age2, age3, age4});
}