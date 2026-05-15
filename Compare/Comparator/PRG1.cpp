#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first; // if second equal, compare by first
    return a.second > b.second;   // sort by second in descending
}

int main()
{
    vector<pair<int, int>> v = {{1, 3}, {2, 2}, {3, 2}, {4, 1}};

    sort(v.begin(), v.end(), cmp);

    cout << "Sorted pairs:\n";
    for (auto &x : v)
        cout << x.first << " " << x.second << "\n";
    return 0;
}
