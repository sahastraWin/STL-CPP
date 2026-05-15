#include <bits/stdc++.h>
using namespace std;

// Custom comparator for descending order of keys
struct DescOrder
{
    bool operator()(const int &a, const int &b) const
    {
        return a > b;
    }
};

int main()
{
    // ---------- 1. Creation ----------
    map<int, string> m;                // ascending order of keys
    map<int, string, DescOrder> mdesc; // descending order of keys
    multimap<int, string> mm;          // allows duplicate keys

    // ---------- 2. Insertion ----------
    m[5] = "five";
    m[3] = "three";
    m[1] = "one";
    m[3] = "THREE"; // overwrites value for key 3

    mm.insert({5, "five"});
    mm.insert({3, "three"});
    mm.insert({3, "THREE"}); // duplicate key stored
    mm.insert({1, "one"});

    // ---------- 3. Size / Empty ----------
    cout << "Size of map: " << m.size() << "\n";
    cout << "Is map empty? " << (m.empty() ? "Yes" : "No") << "\n";

    // ---------- 4. Iteration ----------
    cout << "Elements in map: ";
    for (auto &p : m)
        cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n";

    cout << "Reverse order: ";
    for (auto it = m.rbegin(); it != m.rend(); ++it)
        cout << "(" << it->first << "," << it->second << ") ";
    cout << "\n";

    // ---------- 5. Find ----------
    auto fit = m.find(3);
    if (fit != m.end())
        cout << "Found key 3 with value: " << fit->second << "\n";

    // ---------- 6. Erase ----------
    m.erase(3);
    auto it = m.find(5);
    if (it != m.end())
        m.erase(it);

    cout << "After erasing, map: ";
    for (auto &p : m)
        cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n";

    // ---------- 7. Count (multimap) ----------
    cout << "Count of key 3 in multimap: " << mm.count(3) << "\n";

    // ---------- 8. Lower & Upper Bound ----------
    map<int, string> m2 = {{1, "one"}, {2, "two"}, {4, "four"}, {6, "six"}};
    auto lb = m2.lower_bound(3); // >= 3
    auto ub = m2.upper_bound(4); // > 4
    if (lb != m2.end())
        cout << "Lower bound of 3: " << lb->first << "\n";
    if (ub != m2.end())
        cout << "Upper bound of 4: " << ub->first << "\n";

    // ---------- 9. Equal Range ----------
    multimap<int, string> mm2 = {{1, "one"}, {3, "three"}, {3, "THREE"}, {5, "five"}};
    auto range = mm2.equal_range(3);
    cout << "Equal range for key 3: ";
    for (auto i = range.first; i != range.second; ++i)
        cout << "(" << i->first << "," << i->second << ") ";
    cout << "\n";

    // ---------- 10. Swap ----------
    map<int, string> a = {{10, "ten"}, {20, "twenty"}};
    map<int, string> b = {{30, "thirty"}, {40, "forty"}};
    a.swap(b);
    cout << "After swap, map a: ";
    for (auto &p : a)
        cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n";

    // ---------- 11. Merge (C++17) ----------
#if __cplusplus >= 201703L
    map<int, string> m3 = {{1, "one"}, {3, "three"}};
    map<int, string> m4 = {{2, "two"}, {4, "four"}};
    m3.merge(m4); // moves keys not present
#else
    map<int, string> m3 = {{1, "one"}, {3, "three"}};
    map<int, string> m4 = {{2, "two"}, {4, "four"}};
    m3.insert(m4.begin(), m4.end());
    m4.clear();
#endif
    cout << "After merge, m3: ";
    for (auto &p : m3)
        cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n";

    // ---------- 12. Extract Node (C++17) ----------
#if __cplusplus >= 201703L
    map<int, string> m5 = {{1, "one"}, {2, "two"}, {3, "three"}};
    auto nh = m5.extract(2);
    cout << "Extracted key: " << nh.key() << " value: " << nh.mapped() << "\n";
    m5.insert(move(nh));
#else
    map<int, string> m5 = {{1, "one"}, {2, "two"}, {3, "three"}};
    auto itx = m5.find(2);
    if (itx != m5.end())
    {
        int k = itx->first;
        string v = itx->second;
        cout << "Extracted key: " << k << " value: " << v << "\n";
        m5.erase(itx);
        m5.insert({k, v});
    }
#endif
    cout << "After re-inserting: ";
    for (auto &p : m5)
        cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n";

    // ---------- 13. Clear ----------
    m5.clear();
    cout << "After clear, size of m5: " << m5.size() << "\n";
}

/*
| Operation                          | Code Reference                               | Average Time Complexity                           | Worst-case Time Complexity | Extra Space Complexity |
| ---------------------------------- | -------------------------------------------- | ------------------------------------------------- | -------------------------- | ---------------------- |
| **Creation (empty)**               | `map<int,string> m; multimap<int,string> mm;`| **O(1)**                                          | **O(1)**                   | **O(1)**               |
| **Insertion (single element)**     | `m.insert({k,v})` / `mm.insert({k,v})`       | **O(log n)**                                      | **O(log n)**               | **O(1)**               |
| **Insertion (via subscript)**      | `m[k] = v;`                                  | **O(log n)** (insert if key not found, else update)| **O(log n)**               | **O(1)**               |
| **Insertion (range)**              | `m.insert(m2.begin(), m2.end())`             | **O(m log(n+m))**                                 | **O(m log(n+m))**          | **O(1)**               |
| **Size**                           | `m.size()`                                   | **O(1)**                                          | **O(1)**                   | **O(1)**               |
| **Empty check**                    | `m.empty()`                                  | **O(1)**                                          | **O(1)**                   | **O(1)**               |
| **Iteration (full)**               | `for (auto &p : m)`                          | **O(n)**                                          | **O(n)**                   | **O(1)**               |
| **Reverse iteration (full)**       | `rbegin()` to `rend()`                       | **O(n)**                                          | **O(n)**                   | **O(1)**               |
| **Find by key**                    | `m.find(k)`                                  | **O(log n)**                                      | **O(log n)**               | **O(1)**               |
| **Erase by key**                   | `m.erase(k)`                                 | **O(log n)**                                      | **O(log n)**               | **O(1)**               |
| **Erase by iterator**              | `m.erase(it)`                                | **O(log n)**                                      | **O(log n)**               | **O(1)**               |
| **Count (multimap)**               | `mm.count(k)`                                | **O(log n + k)** where `k` = number of duplicates | **O(log n + k)**           | **O(1)**               |
| **Lower bound (by key)**           | `m.lower_bound(k)`                           | **O(log n)**                                      | **O(log n)**               | **O(1)**               |
| **Upper bound (by key)**           | `m.upper_bound(k)`                           | **O(log n)**                                      | **O(log n)**               | **O(1)**               |
| **Equal range (multimap)**         | `mm.equal_range(k)`                          | **O(log n + k)**                                  | **O(log n + k)**           | **O(1)**               |
| **Swap**                           | `m1.swap(m2)`                                | **O(1)**                                          | **O(1)**                   | **O(1)**               |
| **Merge (C++17)**                  | `m1.merge(m2)`                               | **O(m log(n+m))**                                 | **O(m log(n+m))**          | **O(1)**               |
| **Extract node (C++17)**           | `auto nh = m.extract(k)`                     | **O(log n)**                                      | **O(log n)**               | **O(1)**               |
| **Clear**                          | `m.clear()`                                  | **O(n)**                                          | **O(n)**                   | **O(1)**               |
| **Access/Update via key**          | `m[k]`                                       | **O(log n)** (insert if not found) / **O(log n)** update | **O(log n)**               | **O(1)**               |
*/
