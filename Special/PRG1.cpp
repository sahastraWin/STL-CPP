#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {3, 1, 4, 1, 5, 9, 2};

    // 1. count -> Count how many times a value appears
    int cnt = count(v.begin(), v.end(), 1);  
    cout << "Number of 1's = " << cnt << endl;  

    // 2. find -> Returns iterator to first occurrence, or end()
    auto it = find(v.begin(), v.end(), 4);  
    if (it != v.end()) cout << "Found 4 at index " << (it - v.begin()) << endl;

    // 3. all_of -> Check if ALL satisfy condition
    bool allPositive = all_of(v.begin(), v.end(), [](int x){ return x > 0; });
    cout << "All positive? " << (allPositive ? "Yes" : "No") << endl;

    // 4. any_of -> Check if ANY satisfy condition
    bool anyEven = any_of(v.begin(), v.end(), [](int x){ return x % 2 == 0; });
    cout << "Any even? " << (anyEven ? "Yes" : "No") << endl;

    // 5. none_of -> Check if NONE satisfy condition
    bool noneNegative = none_of(v.begin(), v.end(), [](int x){ return x < 0; });
    cout << "None negative? " << (noneNegative ? "Yes" : "No") << endl;

    // 6. unique -> Removes consecutive duplicates
    // Note: works only on sorted or consecutive elements
    v = {1,1,2,2,3,3,3,4};
    auto newEnd = unique(v.begin(), v.end());  
    v.erase(newEnd, v.end());  // remove garbage after unique
    // v = {1,2,3,4}

    // 7. binary_search -> Fast search in SORTED array
    sort(v.begin(), v.end());  
    cout << "Is 3 present? " << (binary_search(v.begin(), v.end(), 3) ? "Yes" : "No") << endl;

    // 8. fill -> Fill entire range with a value
    vector<int> f(5);
    fill(f.begin(), f.end(), 7);  
    // f = {7,7,7,7,7}

    // 9. iota -> Fill with increasing sequence
    iota(f.begin(), f.end(), 10);  
    // f = {10,11,12,13,14}

    // 10. partition -> Reorder elements so that condition true comes first
    vector<int> arr = {1,2,3,4,5,6};
    partition(arr.begin(), arr.end(), [](int x){ return x%2==0; });
    // arr = {2,4,6,3,5,1}  (evens first, then odds)

    return 0;
}
