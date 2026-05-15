#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ---------------- Unordered Set ----------------
    unordered_set<int> b;
    b.insert(2);
    b.insert(5);
    b.insert(5); // no effect (duplicates not allowed)

    if (b.find(2) != b.end())
        cout << "Found\n";
    else
        cout << "Not found\n";

    // ---------------- Ordered Set ----------------
    set<int> g;
    g.insert(2);
    g.insert(5);
    g.insert(5); // no effect (duplicates not allowed)

    if (g.find(2) != g.end())
        cout << "Found\n";
    else
        cout << "Not found\n";

    return 0;
}

/*
Time & Space Complexity Analysis:

| Operation       | unordered_set                | set            |
| --------------- | ---------------------------- | -------------- |
| Insert          | O(1) avg, O(n) worst         | O(log n)       |
| Find / Search   | O(1) avg, O(n) worst         | O(log n)       |
| Delete          | O(1) avg, O(n) worst         | O(log n)       |
| Maintain order? | ❌ No                        | ✅ Yes (sorted)|
| Duplicates?     | ❌ No                        | ❌ No          |

Extra Space Complexity:
- `unordered_set`: O(n) (hash table)
- `set`: O(n) (balanced BST, Red-Black Tree)
*/
