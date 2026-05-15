#include <bits/stdc++.h>
using namespace std;

template <typename K, typename V>
pair<K, V> bigger(map<K, V> &mp, K key)
{
    if (mp.empty())
        return {K(), V()};         // indicate no elements
    auto it = mp.upper_bound(key); // first key > given key
    if (it == mp.end())
        return {K(), V()}; // no bigger
    return *it;            // pair<key,value>
}

template <typename K, typename V>
pair<K, V> smaller(map<K, V> &mp, K key)
{
    if (mp.empty())
        return {K(), V()};
    auto it = mp.lower_bound(key); // first key >= given key
    if (it == mp.begin())
        return {K(), V()}; // no smaller
    --it;
    return *it;
}

int main()
{
    map<int, string> mp;
    mp[2] = "two";
    mp[4] = "four";
    mp[6] = "six";
    mp[8] = "eight";

    auto b = bigger(mp, 2);
    if (b.second != "")
        cout << "Bigger than 2: " << b.first << " -> " << b.second << "\n";
    else
        cout << "No bigger element\n";

    auto s = smaller(mp, 1);
    if (s.second != "")
        cout << "Smaller than 1: " << s.first << " -> " << s.second << "\n";
    else
        cout << "No smaller element\n";
}
/*
| Function                               | Purpose                                                                              | Steps                                                                                                                                                                                                                     | Time Complexity         | Space Complexity |
| -------------------------------------- | ------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------- | ---------------- |
| **bigger(map<K,V> &mp, K key)**        | Returns the *(key, value)* pair in `mp` with the **smallest key strictly greater** than `key`. | 1. If `mp` is empty → return `{K(), V()}`.<br>2. Use `upper_bound(key)` to find the first key > given key.<br>3. If `upper_bound` reaches `end()` → return `{K(), V()}`.<br>4. Else return the *(key,value)* pair.      | `upper_bound` → O(log n) | O(1) extra       |
| **smaller(map<K,V> &mp, K key)**       | Returns the *(key, value)* pair in `mp` with the **largest key strictly less** than `key`.    | 1. If `mp` is empty → return `{K(), V()}`.<br>2. Use `lower_bound(key)` to find the first key >= given key.<br>3. If iterator is at `begin()` → no smaller exists → return `{K(), V()}`.<br>4. Else step back and return. | `lower_bound` → O(log n) | O(1) extra       |
| **main() inserts**                     | Demonstrates `map` insertion using subscript operator.                               | Inserts 4 keys: each `mp[k] = v;` is O(log n) if inserting, O(log n) if updating.                                                                                                                                         | 4 × O(log n)             | O(n) total storage |
| **Overall**                            | Both functions + inserts run efficiently using map’s balanced BST properties.        | All operations (`find`, `upper_bound`, `lower_bound`, `insert`) are O(log n).                                                                                                                                            | O(log n) per query       | O(n) total       |
*/
