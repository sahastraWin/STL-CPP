#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 1. rotate
    vector<int> v1 = {1, 2, 3, 4, 5};
    rotate(v1.begin(), v1.begin() + 2, v1.end());
    cout << "1. rotate -> ";
    for (int x : v1)
        cout << x << " ";
    cout << "\n";

    // 2. next_permutation
    vector<int> v2 = {1, 2, 3};
    next_permutation(v2.begin(), v2.end());
    cout << "2. next_permutation -> ";
    for (int x : v2)
        cout << x << " ";
    cout << "\n";

    // 3. prev_permutation
    prev_permutation(v2.begin(), v2.end());
    cout << "3. prev_permutation -> ";
    for (int x : v2)
        cout << x << " ";
    cout << "\n";

    // 4. unique
    vector<int> v3 = {1, 1, 2, 2, 3, 3, 4};
    auto it = unique(v3.begin(), v3.end());
    v3.erase(it, v3.end());
    cout << "4. unique -> ";
    for (int x : v3)
        cout << x << " ";
    cout << "\n";

    // 5. accumulate
    vector<int> v4 = {1, 2, 3, 4, 5};
    cout << "5. accumulate sum -> " << accumulate(v4.begin(), v4.end(), 0) << "\n";

    // 6. partition
    vector<int> v5 = {1, 2, 3, 4, 5, 6};
    partition(v5.begin(), v5.end(), [](int x)
              { return x % 2 == 0; });
    cout << "6. partition (evens first) -> ";
    for (int x : v5)
        cout << x << " ";
    cout << "\n";

    // 7. stable_partition
    stable_partition(v5.begin(), v5.end(), [](int x)
                     { return x % 2 != 0; });
    cout << "7. stable_partition (odds first) -> ";
    for (int x : v5)
        cout << x << " ";
    cout << "\n";

    // 8. iota
    vector<int> v6(5);
    iota(v6.begin(), v6.end(), 10);
    cout << "8. iota -> ";
    for (int x : v6)
        cout << x << " ";
    cout << "\n";

    // 9. nth_element
    vector<int> v7 = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    nth_element(v7.begin(), v7.begin() + 4, v7.end());
    cout << "9. nth_element (5th smallest) -> " << v7[4] << "\n";

    // 10. transform
    vector<int> v8 = {1, 2, 3, 4, 5}, v9(5);
    transform(v8.begin(), v8.end(), v9.begin(), [](int x)
              { return x * x; });
    cout << "10. transform (squares) -> ";
    for (int x : v9)
        cout << x << " ";
    cout << "\n";

    // 11. set_union
    vector<int> a = {1, 2, 3, 4}, b = {3, 4, 5, 6}, res;
    set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
    cout << "11. set_union -> ";
    for (int x : res)
        cout << x << " ";
    cout << "\n";

    // 12. adjacent_difference
    vector<int> v10 = {1, 3, 6, 10}, diff(4);
    adjacent_difference(v10.begin(), v10.end(), diff.begin());
    cout << "12. adjacent_difference -> ";
    for (int x : diff)
        cout << x << " ";
    cout << "\n";

    // 13. max_element / min_element
    vector<int> v11 = {10, 20, 5, 30};
    cout << "13. max_element -> " << *max_element(v11.begin(), v11.end())
         << " min_element -> " << *min_element(v11.begin(), v11.end()) << "\n";

    // 14. count / count_if
    cout << "14. count 20 -> " << count(v11.begin(), v11.end(), 20)
         << " count_if (>15) -> " << count_if(v11.begin(), v11.end(), [](int x)
                                              { return x > 15; })
         << "\n";

    // 15. find / find_if
    auto itf = find(v11.begin(), v11.end(), 30);
    cout << "15. find 30 -> index " << distance(v11.begin(), itf) << "\n";

    // 16. equal_range (binary search helpers)
    vector<int> v12 = {1, 2, 2, 2, 3, 4};
    auto pr = equal_range(v12.begin(), v12.end(), 2);
    cout << "16. equal_range for 2 -> [" << distance(v12.begin(), pr.first) << ","
         << distance(v12.begin(), pr.second) << ")\n";

    // 17. binary_search
    cout << "17. binary_search 3 -> " << binary_search(v12.begin(), v12.end(), 3) << "\n";

    // 18. lower_bound / upper_bound
    cout << "18. lower_bound of 2 -> " << distance(v12.begin(), lower_bound(v12.begin(), v12.end(), 2))
         << " upper_bound of 2 -> " << distance(v12.begin(), upper_bound(v12.begin(), v12.end(), 2)) << "\n";

    // 19. includes (check if subset)
    vector<int> v13 = {1, 2, 3, 4, 5}, v14 = {2, 3};
    cout << "19. includes -> " << includes(v13.begin(), v13.end(), v14.begin(), v14.end()) << "\n";

    // 20. inplace_merge
    vector<int> v15 = {1, 3, 5, 7, 2, 4, 6, 8};
    inplace_merge(v15.begin(), v15.begin() + 4, v15.end());
    cout << "20. inplace_merge -> ";
    for (int x : v15)
        cout << x << " ";
    cout << "\n";

    // 21. partial_sort
    vector<int> v16 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    partial_sort(v16.begin(), v16.begin() + 5, v16.end());
    cout << "21. partial_sort (first 5 smallest sorted) -> ";
    for (int x : v16)
        cout << x << " ";
    cout << "\n";

    // 22. stable_sort
    vector<pair<int, int>> v17 = {{1, 3}, {2, 2}, {1, 2}, {2, 1}};
    stable_sort(v17.begin(), v17.end(), [](auto &p1, auto &p2)
                { return p1.first < p2.first; });
    cout << "22. stable_sort -> ";
    for (auto &p : v17)
        cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n";

    // 23. random_shuffle (C++11 deprecated, use shuffle)
    vector<int> v18 = {1, 2, 3, 4, 5};
    random_shuffle(v18.begin(), v18.end());
    cout << "23. random_shuffle -> ";
    for (int x : v18)
        cout << x << " ";
    cout << "\n";

    // 24. shuffle (C++11+)
    shuffle(v18.begin(), v18.end(), default_random_engine(42));
    cout << "24. shuffle -> ";
    for (int x : v18)
        cout << x << " ";
    cout << "\n";

    // 25. fill / fill_n
    vector<int> v19(5);
    fill(v19.begin(), v19.end(), 7);
    cout << "25. fill -> ";
    for (int x : v19)
        cout << x << " ";
    cout << "\n";
    fill_n(v19.begin(), 3, 9);
    cout << "   fill_n -> ";
    for (int x : v19)
        cout << x << " ";
    cout << "\n";

    // 26. generate / generate_n
    int val = 1;
    generate(v19.begin(), v19.end(), [&]()
             { return val++; });
    cout << "26. generate -> ";
    for (int x : v19)
        cout << x << " ";
    cout << "\n";

    // 27. replace / replace_if
    vector<int> v20 = {1, 2, 3, 2, 4};
    replace(v20.begin(), v20.end(), 2, 99);
    cout << "27. replace -> ";
    for (int x : v20)
        cout << x << " ";
    cout << "\n";

    // 28. remove / remove_if
    vector<int> v21 = {1, 2, 3, 4, 5, 6};
    auto newend = remove_if(v21.begin(), v21.end(), [](int x)
                            { return x % 2 == 0; });
    v21.erase(newend, v21.end());
    cout << "28. remove_if (remove evens) -> ";
    for (int x : v21)
        cout << x << " ";
    cout << "\n";

    // 29. reverse / reverse_copy
    vector<int> v22 = {1, 2, 3, 4, 5};
    reverse(v22.begin(), v22.end());
    cout << "29. reverse -> ";
    for (int x : v22)
        cout << x << " ";
    cout << "\n";

    // 30. rotate_copy
    vector<int> v23(5);
    rotate_copy(v22.begin(), v22.begin() + 2, v22.end(), v23.begin());
    cout << "30. rotate_copy -> ";
    for (int x : v23)
        cout << x << " ";
    cout << "\n";

    return 0;
}
