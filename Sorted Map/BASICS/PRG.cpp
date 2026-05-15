/*
Map - Stores key-value pairs in sorted order by key.
      Keys are unique in `map`, but `multimap` allows duplicate keys.

Can perform quick search, insertion, deletion in O(log n) time.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Creation
    map<int, string> mp;                   // ascending order by key
    map<int, string, greater<int>> mpdesc; // descending order by key
    multimap<int, string> mmp;             // allows duplicate keys

    // Insertion
    mp.insert({1, "one"}); // O(log n)
    mp[2] = "two";         // O(log n) (inserts if key not present)
    mp.insert({3, "three"});
    mp.insert({2, "duplicate"}); // key already exists → value unchanged

    // For multimap
    mmp.insert({1, "first"});
    mmp.insert({1, "second"}); // duplicates allowed

    // Size & Empty
    cout << mp.size() << "\n";  // O(1)
    cout << mp.empty() << "\n"; // O(1)

    // Search
    if (mp.find(2) != mp.end()) // O(log n)
        cout << "Found key 2\n";

    // Access value by key (only for map, not multimap)
    cout << mp[2] << "\n"; // O(log n)

    // Erase by key
    mp.erase(3); // O(log n)

    // Erase by iterator
    auto it = mp.find(1);
    if (it != mp.end())
        mp.erase(it); // O(log n)

    // Count occurrences (useful for multimap)
    cout << mmp.count(1) << "\n"; // O(log n + k), k = duplicates

    // Clear all elements
    mp.clear(); // O(n)
}

/*
| Operation                         | Code Reference                         | Average Time Complexity                            | Worst-case Time Complexity | Extra Space Complexity |
| --------------------------------- | -------------------------------------- | -------------------------------------------------- | -------------------------- | ---------------------- |
| **Creation (empty)**              | `map<int,string> mp;`                  | **O(1)**                                           | **O(1)**                   | **O(1)**               |
| **Insertion (single)**            | `mp.insert({1,"one"})`                 | **O(log n)**                                       | **O(log n)**               | **O(1)**               |
| **Insertion / Update (operator)** | `mp[key] = val;`                        | **O(log n)**                                       | **O(log n)**               | **O(1)**               |
| **Size**                          | `mp.size()`                             | **O(1)**                                           | **O(1)**                   | **O(1)**               |
| **Empty check**                   | `mp.empty()`                            | **O(1)**                                           | **O(1)**                   | **O(1)**               |
| **Find key**                      | `mp.find(key)`                          | **O(log n)**                                       | **O(log n)**               | **O(1)**               |
| **Access value by key**           | `mp[key]`                               | **O(log n)**                                       | **O(log n)**               | **O(1)**               |
| **Erase by key**                  | `mp.erase(key)`                         | **O(log n)**                                       | **O(log n)**               | **O(1)**               |
| **Erase by iterator**             | `mp.erase(it)`                          | **O(log n)**                                       | **O(log n)**               | **O(1)**               |
| **Count (multimap)**              | `mmp.count(key)`                        | **O(log n + k)**, where `k` = duplicates           | **O(log n + k)**           | **O(1)**               |
| **Clear all elements**            | `mp.clear()`                            | **O(n)**                                           | **O(n)**                   | **O(1)**               |
*/
