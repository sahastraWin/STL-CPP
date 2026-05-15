#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Custom comparator (descending order)
    auto cmp = [](int a, int b)
    {
        return a > b;
    };

    set<int, decltype(cmp)> s(cmp); // must specify comparator type

    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(15);

    cout << "Set with lambda comparator: ";
    for (int x : s)
        cout << x << " "; // 20 15 10 5
    cout << "\n";
    return 0;
}
