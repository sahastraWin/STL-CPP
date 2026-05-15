#include <bits/stdc++.h>
using namespace std;

// Custom comparator: descending order
struct cmp
{
    bool operator()(const int &a, const int &b) const
    {
        return a > b;
    }
};

int main()
{
    set<int, cmp> s = {10, 5, 20, 15};

    cout << "Custom ordered set: ";
    for (int x : s)
        cout << x << " "; // 20 15 10 5
    cout << "\n";
    return 0;
}
