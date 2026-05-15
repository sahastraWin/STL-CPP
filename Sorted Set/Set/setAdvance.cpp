#include <bits/stdc++.h>
using namespace std;

int main()
{
    // =====================================================
    // 1. unordered_set (No order, Unique keys)
    // =====================================================
    unordered_set<int> us;

    us.insert(10);
    us.insert(5);
    us.insert(15);
    us.insert(5); // duplicate ignored

    cout << "unordered_set elements: ";
    for (auto x : us)
        cout << x << " ";
    cout << "\n";

    cout << (us.find(10) != us.end() ? "Found 10\n" : "Not Found 10\n");

    us.erase(5);
    cout << "Count of 15: " << us.count(15) << "\n";
    cout << "Size: " << us.size() << "\n";
    cout << "Empty? " << (us.empty() ? "Yes" : "No") << "\n";
    cout << "Bucket count: " << us.bucket_count() << "\n";
    cout << "Load factor: " << us.load_factor() << "\n\n";

    // =====================================================
    // 2. set (Ordered set, Unique keys)
    // =====================================================
    set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(5); // duplicate ignored

    cout << "set elements (sorted): ";
    for (auto x : s)
        cout << x << " ";
    cout << "\n";

    cout << (s.find(15) != s.end() ? "Found 15\n" : "Not Found 15\n");
    cout << "Lower bound of 10: " << *s.lower_bound(10) << "\n";
    cout << "Upper bound of 10: " << *s.upper_bound(10) << "\n";

    s.erase(5);
    cout << "Count of 15: " << s.count(15) << "\n\n";

    // =====================================================
    // 3. unordered_multiset (No order, allows duplicates)
    // =====================================================
    unordered_multiset<int> ums;
    ums.insert(10);
    ums.insert(5);
    ums.insert(10);
    ums.insert(5);

    cout << "unordered_multiset elements: ";
    for (auto x : ums)
        cout << x << " ";
    cout << "\n";

    cout << "Count of 10: " << ums.count(10) << "\n";

    auto it = ums.find(5);
    if (it != ums.end())
        ums.erase(it);

    cout << "Elements after erasing one 5: ";
    for (auto x : ums)
        cout << x << " ";
    cout << "\n\n";

    // =====================================================
    // 4. multiset (Ordered, allows duplicates)
    // =====================================================
    multiset<int> ms;
    ms.insert(10);
    ms.insert(5);
    ms.insert(10);
    ms.insert(15);

    cout << "multiset elements (sorted): ";
    for (auto x : ms)
        cout << x << " ";
    cout << "\n";

    cout << "Count of 10: " << ms.count(10) << "\n";

    auto range = ms.equal_range(10);
    cout << "All 10s: ";
    for (auto itr = range.first; itr != range.second; ++itr)
        cout << *itr << " ";
    cout << "\n";

    return 0;
}

/*
====================================================================
Time Complexity (n = number of elements)
====================================================================
| Container              | Insert            | Find/Search      | Erase            | Maintain Order | Duplicate Keys? |
|------------------------|-------------------|------------------|------------------|----------------|-----------------|
| unordered_set          | O(1) avg, O(n)    | O(1) avg, O(n)   | O(1) avg, O(n)   | ❌ No          | ❌ No           |
| set                    | O(log n)          | O(log n)         | O(log n)         | ✅ Yes         | ❌ No           |
| unordered_multiset     | O(1) avg, O(n)    | O(1) avg, O(n)   | O(1) avg, O(n)   | ❌ No          | ✅ Yes          |
| multiset               | O(log n)          | O(log n)         | O(log n)         | ✅ Yes         | ✅ Yes          |
====================================================================
Space Complexity:
- Ordered containers (set, multiset): O(n) for elements + O(log n) tree overhead
- Unordered containers (unordered_set, unordered_multiset): O(n) avg, more due to hash bucket overhead
====================================================================
*/
