#include <bits/stdc++.h>
using namespace std;

int bigger(multiset<int> &s, int vl)
{
    if (s.empty())
    {
        return -2; // no elements at all
    }
    auto itr = s.upper_bound(vl); // first element strictly greater than vl
    if (itr == s.end())
    {
        return -1; // nothing bigger
    }
    return *itr;
}

int smaller(multiset<int> &s, int vl)
{
    if (s.empty())
    {
        return -2; // no elements at all
    }
    auto itr = s.find(vl);
    if (itr != s.end())
    { // exact match found
        if (itr == s.begin())
        {
            return -1; // vl is smallest in the set → nothing smaller
        }
        --itr; // move to previous smaller element
        return *itr;
    }
    else
    {                            // exact match not found
        itr = s.upper_bound(vl); // first element > vl
        if (itr == s.begin())
        {
            return -1; // all elements are >= vl → nothing smaller
        }
        --itr; // largest element <= vl
        return *itr;
    }
}

int main()
{
    multiset<int> s;
    s.insert(2);
    s.insert(4);
    s.insert(6);
    s.insert(8);

    int v1 = bigger(s, 2); // should give 4
    cout << v1 << " ";

    v1 = smaller(s, 1); // should give -1
    cout << v1;
}
/*
| Function                               | Purpose                                                                            | Steps                                                                                                                                                                                                                                                                                                     | Time Complexity                               | Space Complexity   |
| -------------------------------------- | ---------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------- | ------------------ |
| **bigger(multiset<int> \&s, int vl)**  | Returns the smallest element in `s` that is **strictly greater** than `vl`.        | 1. If `s` is empty → return **-2**.<br>2. Use `upper_bound(vl)` to find the first element > `vl`.<br>3. If `upper_bound` reaches `end()` → return **-1**.<br>4. Else dereference iterator and return the value.                                                                                           | `upper_bound` → **O(log n)**                  | O(1) extra         |
| **smaller(multiset<int> \&s, int vl)** | Returns the largest element in `s` that is **strictly less** than `vl`.            | 1. If `s` is empty → return **-2**.<br>2. Check `find(vl)`: if found and it’s the first element → return **-1**, else move iterator back and return value.<br>3. If not found → use `upper_bound(vl)`.<br>4. If `upper_bound` is at `begin()` → return **-1**.<br>5. Else step one back and return value. | `find` + `upper_bound` → **O(log n)** overall | O(1) extra         |
| **main() inserts**                     | Demonstrates insertion in `multiset`.                                              | Insert 4 elements: each `insert` is O(log n).                                                                                                                                                                                                                                                             | 4 × O(log n) = O(log n)                       | O(n) total storage |
| **Overall**                            | Both functions + inserts run efficiently using multiset’s balanced BST properties. | -                                                                                                                                                                                                                                                                                                         | **O(log n)** per query                        | **O(n)** total     |


multiset is implemented as a Red-Black Tree in C++ STL.

find, insert, erase, lower_bound, and upper_bound are O(log n).

Space complexity is proportional to the number of stored elements.

insert(x) :- any element x can be inserted in the set 

remove(x) :- any element x can be removed from the set 

biggest() :- output the biggest number in the set 
smallest() :- outputs the smallest element in the set 

smaller(x) :- outputs the value just smaller than x in the set 

bigger(y) :- outputs the value just bigger than y 

find(y) finds if y is existing or not 

 In general all these operations take O(logN) times in different languages. 

*/