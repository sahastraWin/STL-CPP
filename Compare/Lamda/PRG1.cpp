#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int>> v = {{1, 3}, {2, 2}, {3, 2}, {4, 1}};

    // Sort by second desc, then first asc
    sort(v.begin(), v.end(), [](auto &a, auto &b)
         {
        if (a.second == b.second) 
            return a.first < b.first;
        return a.second > b.second; });

    cout << "Sorted pairs:\n";
    for (auto &x : v)
        cout << x.first << " " << x.second << "\n";
    return 0;
}
