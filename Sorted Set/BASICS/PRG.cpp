/*
Set - Can store elements in sorted order inside itself. Can anytime tell the biggest and smallest number in the set

Can also perform smaller(x) and bigger(y) functions.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Creation
    set<int> s;                   // ascending order
    set<int, greater<int>> sdesc; // descending order
    multiset<int> ms;             // allows duplicates

    // Insertion
    s.insert(5);             // O(log n)
    s.insert({1, 3, 3, 2});  // 3 ignored in set
    ms.insert({1, 3, 3, 2}); // duplicates allowed

    // Size & Empty
    cout << s.size() << "\n";  // O(1)
    cout << s.empty() << "\n"; // O(1)

    // Search
    if (s.find(3) != s.end())
    { // O(log n)
        cout << "Found\n";
    }

    // Erase by value
    s.erase(3); // O(log n)

    // Erase by iterator
    auto it = s.find(5);
    if (it != s.end())
        s.erase(it); // O(log n)

    // Count occurrences (useful in multiset)
    cout << ms.count(3) << "\n"; // O(log n) + number of occurrences

    // Clear all elements
    s.clear(); // O(n)
}
/*
| Operation                        | Code Reference                    | Average Time Complexity                            | Worst-case Time Complexity | Extra Space Complexity |
| -------------------------------- | --------------------------------- | -------------------------------------------------- | -------------------------- | ---------------------- |
| **Creation (empty)**             | `set<int> s;` `multiset<int> ms;` | **O(1)**                                           | **O(1)**                   | **O(1)**               |
| **Insertion (single)**           | `s.insert(5)`                     | **O(log n)**                                       | **O(log n)**               | **O(1)**               |
| **Insertion (initializer list)** | `s.insert({1,3,3,2})`             | **O(m log(n+m))**                                  | **O(m log(n+m))**          | **O(1)**               |
| **Size**                         | `s.size()`                        | **O(1)**                                           | **O(1)**                   | **O(1)**               |
| **Empty check**                  | `s.empty()`                       | **O(1)**                                           | **O(1)**                   | **O(1)**               |
| **Find element**                 | `s.find(3)`                       | **O(log n)**                                       | **O(log n)**               | **O(1)**               |
| **Erase by value**               | `s.erase(3)`                      | **O(log n)**                                       | **O(log n)**               | **O(1)**               |
| **Erase by iterator**            | `s.erase(it)`                     | **O(log n)**                                       | **O(log n)**               | **O(1)**               |
| **Count (multiset)**             | `ms.count(3)`                     | **O(log n + k)**, where `k` = number of duplicates | **O(log n + k)**           | **O(1)**               |
| **Clear all elements**           | `s.clear()`                       | **O(n)**                                           | **O(n)**                   | **O(1)**               |

*/