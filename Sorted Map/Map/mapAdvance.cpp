#include <bits/stdc++.h>
using namespace std;

int main()
{
    // =====================================================
    // 1. unordered_map (No order, unique keys)
    // =====================================================
    unordered_map<int, string> um;
    um[1] = "One";
    um[2] = "Two";
    um.insert({3, "Three"});

    cout << "unordered_map elements: ";
    for (auto &p : um)
        cout << p.first << ":" << p.second << " ";
    cout << "\n";

    if (um.find(2) != um.end())
        cout << "Found key 2\n";

    um.erase(1);
    cout << "Bucket count: " << um.bucket_count() << "\n\n";

    // =====================================================
    // 2. map (Ordered map, unique keys)
    // =====================================================
    map<int, string> m;
    m[1] = "One";
    m[2] = "Two";
    m.insert({3, "Three"});

    cout << "map elements (sorted by key): ";
    for (auto &p : m)
        cout << p.first << ":" << p.second << " ";
    cout << "\n";

    cout << "Lower bound of 2: " << m.lower_bound(2)->first << "\n";
    cout << "Upper bound of 2: " << m.upper_bound(2)->first << "\n\n";

    // =====================================================
    // 3. unordered_multimap (No order, allows duplicate keys)
    // =====================================================
    unordered_multimap<int, string> umm;
    umm.insert({1, "One"});
    umm.insert({2, "Two"});
    umm.insert({1, "Uno"});

    cout << "unordered_multimap elements: ";
    for (auto &p : umm)
        cout << p.first << ":" << p.second << " ";
    cout << "\n";

    auto r1 = umm.equal_range(1);
    cout << "All values for key=1: ";
    for (auto itr = r1.first; itr != r1.second; ++itr)
        cout << itr->second << " ";
    cout << "\n\n";

    // =====================================================
    // 4. multimap (Ordered, allows duplicate keys)
    // =====================================================
    multimap<int, string> mm;
    mm.insert({1, "One"});
    mm.insert({2, "Two"});
    mm.insert({1, "Uno"});

    cout << "multimap elements (sorted by key): ";
    for (auto &p : mm)
        cout << p.first << ":" << p.second << " ";
    cout << "\n";

    auto r2 = mm.equal_range(1);
    cout << "All values for key=1: ";
    for (auto itr = r2.first; itr != r2.second; ++itr)
        cout << itr->second << " ";
    cout << "\n";

    return 0;
}

/*
====================================================================
Time Complexity (n = number of elements)
====================================================================
| Container              | Insert            | Find/Search      | Erase            | Maintain Order | Duplicate Keys? |
|------------------------|-------------------|------------------|------------------|----------------|-----------------|
| unordered_map          | O(1) avg, O(n)    | O(1) avg, O(n)   | O(1) avg, O(n)   | ❌ No          | ❌ No           |
| map                    | O(log n)          | O(log n)         | O(log n)         | ✅ Yes         | ❌ No           |
| unordered_multimap     | O(1) avg, O(n)    | O(1) avg, O(n)   | O(1) avg, O(n)   | ❌ No          | ✅ Yes          |
| multimap               | O(log n)          | O(log n)         | O(log n)         | ✅ Yes         | ✅ Yes          |
====================================================================
Space Complexity:
- Ordered containers (map, multimap): O(n) for elements + O(log n) tree overhead
- Unordered containers (unordered_map, unordered_multimap): O(n) avg, more due to hash bucket overhead
====================================================================
*/
