/*
1. Using resize after declaration
vector<vector<int>> queries;
queries.resize(q, vector<int>(3));

👉 First declare an empty 2D vector, then resize it to q rows, each having 3 integers.

------------------------------------------------------------

2. Using nested vector initialization
vector<vector<int>> queries(q, vector<int>(3, 0));

👉 Here the 0 explicitly initializes all values to zero (though default is also 0).

------------------------------------------------------------

3. Using assign
vector<vector<int>> queries;
queries.assign(q, vector<int>(3));

👉 Similar to resize, but assign resets the vector with new values.

------------------------------------------------------------

4. Using C-style 2D array (only if q is known at compile-time)
int queries[q][3];   // works only if q is a constant

👉 Not flexible like vectors (no dynamic resizing).

------------------------------------------------------------

5. Using array (if size is fixed = 3 per query)
vector<array<int, 3>> queries(q);

👉 Better performance than vector<int>(3) because array<int,3> is a fixed-size structure for each row.

------------------------------------------------------------

6. Using pair + int (if queries are like (type, x, y))
vector<tuple<int,int,int>> queries(q);

👉 Each query is stored as a tuple of 3 integers instead of a small vector.

------------------------------------------------------------
⚡ Summary:

Most common → vector<vector<int>> queries(q, vector<int>(3));

More efficient (since row size is fixed) → vector<array<int,3>> queries(q);

If query has fixed 3 elements with names → use struct instead.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q, n;
    cin >> q >> n;

    cout << "\n=== 1. vector<vector<int>> (classic 2D vector) ===\n";
    vector<vector<int>> queries1(q, vector<int>(n));
    for (int i = 0; i < q; i++)
        for (int j = 0; j < n; j++)
            cin >> queries1[i][j];
    for (auto &row : queries1)
    {
        for (auto x : row)
            cout << x << " ";
        cout << "\n";
    }

    cout << "\n=== 2. vector<vector<int>> (jagged rows, different lengths) ===\n";
    vector<vector<int>> queries2(q);
    for (int i = 0; i < q; i++)
    {
        int len;
        cin >> len; // row-specific length
        queries2[i].resize(len);
        for (int j = 0; j < len; j++)
            cin >> queries2[i][j];
    }
    for (auto &row : queries2)
    {
        for (auto x : row)
            cout << x << " ";
        cout << "\n";
    }

    cout << "\n=== 3. vector<array<int, N>> (fixed N at compile time) ===\n";
    // works only if N is known at compile-time
    const int N = 3; // example fixed size
    vector<array<int, N>> queries3(q);
    for (int i = 0; i < q; i++)
        for (int j = 0; j < N; j++)
            cin >> queries3[i][j];
    for (auto &row : queries3)
    {
        for (auto x : row)
            cout << x << " ";
        cout << "\n";
    }

    cout << "\n=== 4. vector<tuple<int,int,int>> (for exactly 3 elements) ===\n";
    vector<tuple<int, int, int>> queries4(q);
    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        queries4[i] = {a, b, c};
    }
    for (auto &t : queries4)
    {
        int a = get<0>(t);
        int b = get<1>(t);
        int c = get<2>(t);
        cout << a << " " << b << " " << c << "\n";
    }

    cout << "\n=== 5. Flattened 1D vector<int> (manual indexing) ===\n";
    vector<int> queries5(q * n);
    for (int i = 0; i < q; i++)
        for (int j = 0; j < n; j++)
            cin >> queries5[i * n + j]; // row-major indexing
    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < n; j++)
            cout << queries5[i * n + j] << " ";
        cout << "\n";
    }
}
