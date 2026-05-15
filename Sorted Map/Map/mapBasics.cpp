#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ---------------- Unordered Map ----------------
    unordered_map<int, int> d;
    d[2] = 1;
    d[5] = 2;

    if (d.find(2) != d.end())
        cout << "Found\n";
    else
        cout << "Not found\n";

    cout << d[5] << "\n"; // prints value for key 5

    // ---------------- Ordered Map ----------------
    map<int, int> kk;
    kk[2] = 1;
    kk[5] = 2;

    if (kk.find(2) != kk.end())
        cout << "Found\n";
    else
        cout << "Not found\n";

    cout << kk[5] << "\n"; // prints value for key 5

    return 0;
}

/*
Time & Space Complexity Analysis:

| Operation       | unordered_map                | map            |
| --------------- | ---------------------------- | -------------- |
| Insert          | O(1) avg, O(n) worst         | O(log n)       |
| Find / Search   | O(1) avg, O(n) worst         | O(log n)       |
| Delete          | O(1) avg, O(n) worst         | O(log n)       |
| Maintain order? | ❌ No                        | ✅ Yes (sorted)|
| Duplicates?     | ❌ No                        | ❌ No          |

Extra Space Complexity:
- `unordered_map`: O(n) (hash table)
- `map`: O(n) (balanced BST, Red-Black Tree)
*/
