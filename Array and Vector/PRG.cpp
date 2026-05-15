#include <iostream>
#include <vector>
#include <array>
#include <algorithm> // sort, reverse, find, etc.
#include <numeric>   // accumulate
#include <iterator>  // iterators
#include <cassert>

using namespace std;

int main()
{
    // ----------- Static array (std::array) --------------
    array<int, 5> arr = {10, 20, 30, 40, 50};

    cout << "Static array elements: ";
    for (auto &x : arr)
        cout << x << " ";
    cout << "\nSize of std::array: " << arr.size() << "\n";

    cout << "Element at index 2: " << arr.at(2) << "\n";

    // Sort the static array
    sort(arr.begin(), arr.end());
    cout << "Sorted static array: ";
    for (auto &x : arr)
        cout << x << " ";
    cout << "\n";

    // Reverse the static array
    reverse(arr.begin(), arr.end());
    cout << "Reversed static array: ";
    for (auto &x : arr)
        cout << x << " ";
    cout << "\n";

    // Find element in static array
    auto it_arr = find(arr.begin(), arr.end(), 30);
    if (it_arr != arr.end())
        cout << "Element 30 found at index " << distance(arr.begin(), it_arr) << " in static array\n";
    else
        cout << "Element 30 not found in static array\n";

    // Accumulate sum in static array
    int sum_arr = accumulate(arr.begin(), arr.end(), 0);
    cout << "Sum of elements in static array: " << sum_arr << "\n";

    // ----------- Dynamic array: std::vector ------------------
    vector<int> vec = {10, 20, 30, 40, 50};
    cout << "\nVector elements: ";
    for (auto &x : vec)
        cout << x << " ";
    cout << "\nSize of vector: " << vec.size() << "\n";

    vec.push_back(60);
    vec.push_back(70);
    cout << "Vector after push_back(60,70): ";
    for (auto &x : vec)
        cout << x << " ";
    cout << "\nSize after push_back: " << vec.size() << "\n";

    cout << "Element at index 3 using operator[]: " << vec[3] << "\n";
    cout << "Element at index 3 using at(): " << vec.at(3) << "\n";

    vec[0] = 100;
    vec.insert(vec.begin() + 2, 25);
    vec.erase(vec.begin() + 4);

    cout << "Vector after insert and erase: ";
    for (auto &x : vec)
        cout << x << " ";
    cout << "\n";

    vec.resize(5);
    cout << "Vector after resize(5): ";
    for (auto &x : vec)
        cout << x << " ";
    cout << "\n";

    // Accumulate sum in vector (NEW explicit example)
    int sum_vec = accumulate(vec.begin(), vec.end(), 0);
    cout << "Sum of elements in vector: " << sum_vec << "\n";

    vec.clear();
    cout << "Vector size after clear(): " << vec.size() << "\n";

    // ----------- Common STL algorithms on vector ------------------------
    vector<int> v = {5, 3, 8, 1, 9, 7};

    sort(v.begin(), v.end());
    cout << "Sorted vector: ";
    for (auto &x : v)
        cout << x << " ";
    cout << "\n";

    reverse(v.begin(), v.end());
    cout << "Reversed vector: ";
    for (auto &x : v)
        cout << x << " ";
    cout << "\n";

    auto it = find(v.begin(), v.end(), 8);
    if (it != v.end())
        cout << "Element 8 found at index " << distance(v.begin(), it) << "\n";
    else
        cout << "Element 8 not found\n";

    int cnt = count(v.begin(), v.end(), 5);
    cout << "Count of 5 in vector: " << cnt << "\n";

    // Accumulate sum of elements
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "Sum of elements: " << sum << "\n";

    auto max_it = max_element(v.begin(), v.end());
    auto min_it = min_element(v.begin(), v.end());
    cout << "Max element: " << *max_it << ", Min element: " << *min_it << "\n";

    sort(v.begin(), v.end()); // binary_search needs sorted container
    bool present = binary_search(v.begin(), v.end(), 7);
    cout << "Is 7 present (binary_search)? " << (present ? "Yes" : "No") << "\n";

    auto lb = lower_bound(v.begin(), v.end(), 6);
    cout << "Lower bound of 6 is at index " << (lb - v.begin()) << "\n";

    auto ub = upper_bound(v.begin(), v.end(), 6);
    cout << "Upper bound of 6 is at index " << (ub - v.begin()) << "\n";

    // ----------- Key differences summary ------------
    /*
    1. Size:
       - std::array: Fixed size at compile time, size cannot change.
       - vector: Dynamic size, can grow or shrink during runtime.

    2. Memory:
       - std::array: Usually allocated on stack.
       - vector: Allocated on heap (dynamic memory).

    3. Performance:
       - std::array: Slightly faster, no overhead.
       - vector: Slightly slower due to memory management.

    4. Functions:
       - std::array: size(), at(), front(), back(), fill(), swap(), iterators.
         No push_back(), pop_back(), insert(), erase().
       - vector: Supports all std::array functions plus push_back(), pop_back(), insert(), erase(), resize(), capacity(), reserve().

    5. Use case:
       - std::array: When size known and fixed.
       - vector: When size can change or is unknown.

    6. Iterators:
       Both support iterators, so STL algorithms work on both.

    7. Initialization:
       - std::array: Size fixed at compile time.
       - vector: Can be empty initially, elements added later.
    */

    return 0;
}
