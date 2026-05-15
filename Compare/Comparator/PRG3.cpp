#include <bits/stdc++.h>
using namespace std;

// Keys in descending order
struct cmp
{
    bool operator()(const string &a, const string &b) const
    {
        return a > b;
    }
};

int main()
{
    map<string, int, cmp> mp;
    mp["apple"] = 1;
    mp["banana"] = 2;
    mp["cherry"] = 3;

    for (auto &x : mp)
    {
        cout << x.first << " -> " << x.second << "\n";
    }
    return 0;
}
