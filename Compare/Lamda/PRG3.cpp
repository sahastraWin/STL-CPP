#include <bits/stdc++.h>
using namespace std;

int main()
{
    auto cmp = [](const string &a, const string &b)
    {
        return a > b; // descending order
    };

    map<string, int, decltype(cmp)> mp(cmp);

    mp["apple"] = 1;
    mp["banana"] = 2;
    mp["cherry"] = 3;

    for (auto &x : mp)
    {
        cout << x.first << " -> " << x.second << "\n";
    }
    return 0;
}
