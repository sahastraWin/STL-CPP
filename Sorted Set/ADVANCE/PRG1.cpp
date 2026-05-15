#include <bits/stdc++.h>
using namespace std;

// Custom comparator for descending order
struct DescOrder
{
    bool operator()(const int &a, const int &b) const
    {
        return a > b; // reverse sorting
    }
};

int main()
{
    // ---------- 1. Creation ----------
    set<int> s;                // ascending order
    set<int, DescOrder> sdesc; // descending order
    multiset<int> ms;          // allows duplicates

    // ---------- 2. Insertion ----------
    s.insert(5);
    s.insert(3);
    s.insert(1);
    s.insert(3);             // ignored in set
    ms.insert({5, 3, 1, 3}); // duplicates stored

    // ---------- 3. Size / Empty ----------
    cout << "Size of set: " << s.size() << "\n";
    cout << "Is set empty? " << (s.empty() ? "Yes" : "No") << "\n";

    // ---------- 4. Iteration ----------
    cout << "Elements in set: ";
    for (auto x : s)
        cout << x << " ";
    cout << "\n";

    cout << "Reverse order: ";
    for (auto it = s.rbegin(); it != s.rend(); ++it)
        cout << *it << " ";
    cout << "\n";

    // ---------- 5. Find ----------
    if (s.find(3) != s.end())
        cout << "Found 3\n";

    // ---------- 6. Erase ----------
    s.erase(3);
    auto it = s.find(5);
    if (it != s.end())
        s.erase(it);
    cout << "After erasing, set: ";
    for (auto x : s)
        cout << x << " ";
    cout << "\n";

    // ---------- 7. Count ----------
    cout << "Count of 3 in multiset: " << ms.count(3) << "\n";

    // ---------- 8. Lower & Upper Bound ----------
    set<int> s2 = {1, 2, 4, 6};
    auto lb = s2.lower_bound(3); // >= 3
    auto ub = s2.upper_bound(4); // > 4
    if (lb != s2.end())
        cout << "Lower bound of 3: " << *lb << "\n";
    if (ub != s2.end())
        cout << "Upper bound of 4: " << *ub << "\n";

    // ---------- 9. Equal Range ----------
    multiset<int> ms2 = {1, 3, 3, 5};
    auto range = ms2.equal_range(3);
    cout << "Equal range for 3: ";
    for (auto i = range.first; i != range.second; ++i)
        cout << *i << " ";
    cout << "\n";

    // ---------- 10. Swap ----------
    set<int> a = {10, 20};
    set<int> b = {30, 40};
    a.swap(b);
    cout << "After swap, set a: ";
    for (auto x : a)
        cout << x << " ";
    cout << "\n";

    // ---------- 11. Merge (manual for C++14, native for C++17+) ----------
#if __cplusplus >= 201703L
    set<int> s3 = {1, 3};
    set<int> s4 = {2, 4};
    s3.merge(s4); // C++17 feature
#else
    set<int> s3 = {1, 3};
    set<int> s4 = {2, 4};
    s3.insert(s4.begin(), s4.end());
    s4.clear();
#endif
    cout << "After merge, s3: ";
    for (auto x : s3)
        cout << x << " ";
    cout << "\n";

    // ---------- 12. Extract Node (manual for C++14, native for C++17+) ----------
#if __cplusplus >= 201703L
    set<int> s5 = {1, 2, 3};
    auto nh = s5.extract(2);
    cout << "Extracted value: " << nh.value() << "\n";
    s5.insert(move(nh));
#else
    set<int> s5 = {1, 2, 3};
    auto itx = s5.find(2);
    if (itx != s5.end())
    {
        int val = *itx;
        cout << "Extracted value: " << val << "\n";
        s5.erase(itx);
        s5.insert(val);
    }
#endif
    cout << "After re-inserting: ";
    for (auto x : s5)
        cout << x << " ";
    cout << "\n";

    // ---------- 13. Clear ----------
    s5.clear();
    cout << "After clear, size of s5: " << s5.size() << "\n";

    return 0;
}
/*
| Operation                      | Code Reference                   | Average Time Complexity                           | Worst-case Time Complexity | Extra Space Complexity |
| ------------------------------ | -------------------------------- | ------------------------------------------------- | -------------------------- | ---------------------- |
| **Creation (empty)**           | `set<int> s; multiset<int> ms;`  | **O(1)**                                          | **O(1)**                   | **O(1)**               |
| **Insertion (single element)** | `s.insert(x)` / `ms.insert(x)`   | **O(log n)**                                      | **O(log n)**               | **O(1)**               |
| **Insertion (range)**          | `s.insert(s4.begin(), s4.end())` | **O(m log(n+m))**                                 | **O(m log(n+m))**          | **O(1)**               |
| **Size**                       | `s.size()`                       | **O(1)**                                          | **O(1)**                   | **O(1)**               |
| **Empty check**                | `s.empty()`                      | **O(1)**                                          | **O(1)**                   | **O(1)**               |
| **Iteration (full)**           | `for (auto x : s)`               | **O(n)**                                          | **O(n)**                   | **O(1)**               |
| **Reverse iteration (full)**   | `rbegin()` to `rend()`           | **O(n)**                                          | **O(n)**                   | **O(1)**               |
| **Find element**               | `s.find(x)`                      | **O(log n)**                                      | **O(log n)**               | **O(1)**               |
| **Erase by key**               | `s.erase(x)`                     | **O(log n)**                                      | **O(log n)**               | **O(1)**               |
| **Erase by iterator**          | `s.erase(it)`                    | **O(log n)**                                      | **O(log n)**               | **O(1)**               |
| **Count (multiset)**           | `ms.count(x)`                    | **O(log n + k)** where `k` = number of duplicates | **O(log n + k)**           | **O(1)**               |
| **Lower bound**                | `s.lower_bound(x)`               | **O(log n)**                                      | **O(log n)**               | **O(1)**               |
| **Upper bound**                | `s.upper_bound(x)`               | **O(log n)**                                      | **O(log n)**               | **O(1)**               |
| **Equal range**                | `ms.equal_range(x)`              | **O(log n + k)**                                  | **O(log n + k)**           | **O(1)**               |
| **Swap**                       | `a.swap(b)`                      | **O(1)**                                          | **O(1)**                   | **O(1)**               |
| **Merge (C++17)**              | `s3.merge(s4)`                   | **O(m log(n+m))**                                 | **O(m log(n+m))**          | **O(1)**               |
| **Extract node (C++17)**       | `auto nh = s.extract(x)`         | **O(log n)**                                      | **O(log n)**               | **O(1)**               |
| **Clear**                      | `s.clear()`                      | **O(n)**                                          | **O(n)**                   | **O(1)**               |
*/