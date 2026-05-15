#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Create a tuple
    tuple<int, string, double> t1 = make_tuple(10, "ChatGPT", 99.9);

    // Access elements
    cout << "First: " << get<0>(t1) << "\n";
    cout << "Second: " << get<1>(t1) << "\n";
    cout << "Third: " << get<2>(t1) << "\n";

    // Modify element
    get<2>(t1) = 88.8;

    // Unpack using tie
    int id;
    string name;
    double score;
    tie(id, name, score) = t1;

    cout << "Unpacked: " << id << ", " << name << ", " << score << "\n";

    // Concatenate tuples
    tuple<char, bool> t2 = make_tuple('A', true);
    auto t3 = tuple_cat(t1, t2);

    cout << "Concatenated First: " << get<0>(t3) << "\n";
    cout << "Concatenated Last: " << get<4>(t3) << "\n";

    return 0;
}
/*
Time Complexity:

Creation (make_tuple) → O(1)
Access (get<index>) → O(1) (compile-time index lookup).
Modification → O(1).
Concatenation (tuple_cat) → O(N + M) (creates new tuple with size = N+M).
Unpacking (tie) → O(N) (assigns each element).

Space Complexity:

A tuple of size N requires O(N) space (stores all elements directly, no extra pointers).
Each element occupies space equal to its type.
tuple_cat creates a new tuple → needs O(N + M) extra memory.
*/