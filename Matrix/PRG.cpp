#include <iostream>
#include <vector>
#include <algorithm> // sort, reverse
#include <numeric>   // accumulate
#include <iterator>  // distance
using namespace std;

int main()
{
    // ----------- Matrix Initialization ----------------
    // Static size initialization (3x3)
    vector<vector<int>> mat = {
        {3, 5, 1},
        {9, 2, 7},
        {4, 6, 8}};

    cout << "Original Matrix:\n";
    for (auto &row : mat)
    {
        for (auto &x : row)
            cout << x << " ";
        cout << "\n";
    }

    // Dynamic initialization (m x n with default value)
    int m = 4, n = 5;
    vector<vector<int>> dynMat(m, vector<int>(n, 0));

    cout << "\nDynamic 4x5 zero matrix:\n";
    for (auto &row : dynMat)
    {
        for (auto &x : row)
            cout << x << " ";
        cout << "\n";
    }

    // ----------- Access and Modify --------------------
    mat[0][1] = 10; // change element
    cout << "\nAfter modifying mat[0][1] = 10:\n";
    for (auto &row : mat)
    {
        for (auto &x : row)
            cout << x << " ";
        cout << "\n";
    }

    // Insert a new row
    mat.push_back({11, 12, 13});
    cout << "\nAfter inserting new row:\n";
    for (auto &row : mat)
    {
        for (auto &x : row)
            cout << x << " ";
        cout << "\n";
    }

    // Erase a row
    mat.erase(mat.begin() + 1); // delete 2nd row
    cout << "\nAfter erasing row 1:\n";
    for (auto &row : mat)
    {
        for (auto &x : row)
            cout << x << " ";
        cout << "\n";
    }

    // Resize matrix
    mat.resize(2); // keep only 2 rows
    cout << "\nAfter resize to 2 rows:\n";
    for (auto &row : mat)
    {
        for (auto &x : row)
            cout << x << " ";
        cout << "\n";
    }

    // ----------- Row & Column Operations -------------
    vector<int> row = {5, 4, 9, 1, 7};
    sort(row.begin(), row.end()); // ascending
    cout << "\nSorted row ascending: ";
    for (auto x : row)
        cout << x << " ";
    cout << "\n";

    sort(row.begin(), row.end(), greater<int>()); // descending
    cout << "Sorted row descending: ";
    for (auto x : row)
        cout << x << " ";
    cout << "\n";

    // Sort each row of matrix
    vector<vector<int>> mat2 = {
        {9, 3, 5},
        {7, 2, 8},
        {6, 4, 1}};

    for (auto &r : mat2)
        sort(r.begin(), r.end());
    cout << "\nMatrix after sorting each row ascending:\n";
    for (auto &r : mat2)
    {
        for (auto x : r)
            cout << x << " ";
        cout << "\n";
    }

    // ----------- Column-wise operations --------------
    // Extract column
    int colIndex = 1;
    vector<int> col;
    for (auto &r : mat2)
        col.push_back(r[colIndex]);

    cout << "\nColumn " << colIndex << " extracted: ";
    for (auto x : col)
        cout << x << " ";
    cout << "\n";

    // Sort a column
    sort(col.begin(), col.end());
    cout << "Sorted column: ";
    for (auto x : col)
        cout << x << " ";
    cout << "\n";

    // ----------- Accumulate & Count ------------------
    int sumRow = accumulate(mat2[0].begin(), mat2[0].end(), 0);
    cout << "\nSum of first row: " << sumRow << "\n";

    int cnt = count(mat2[0].begin(), mat2[0].end(), 5);
    cout << "Count of 5 in first row: " << cnt << "\n";

    // ----------- Max/Min in Matrix -------------------
    int maxVal = mat2[0][0], minVal = mat2[0][0];
    for (auto &r : mat2)
    {
        maxVal = max(maxVal, *max_element(r.begin(), r.end()));
        minVal = min(minVal, *min_element(r.begin(), r.end()));
    }
    cout << "\nMax element in matrix: " << maxVal << "\n";
    cout << "Min element in matrix: " << minVal << "\n";

    // ----------- Transpose ---------------------------
    vector<vector<int>> transposed(mat2[0].size(), vector<int>(mat2.size()));
    for (int i = 0; i < mat2.size(); i++)
    {
        for (int j = 0; j < mat2[0].size(); j++)
        {
            transposed[j][i] = mat2[i][j];
        }
    }

    cout << "\nTranspose of matrix:\n";
    for (auto &r : transposed)
    {
        for (auto x : r)
            cout << x << " ";
        cout << "\n";
    }

    // ----------- Flatten Matrix ----------------------
    vector<int> flat;
    for (auto &r : mat2)
        flat.insert(flat.end(), r.begin(), r.end());

    cout << "\nFlattened matrix: ";
    for (auto x : flat)
        cout << x << " ";
    cout << "\n";

    sort(flat.begin(), flat.end());
    cout << "Sorted flattened matrix: ";
    for (auto x : flat)
        cout << x << " ";
    cout << "\n";

    // ----------- Key differences summary ------------
    /*
    1. Matrix in STL = vector<vector<T>> (dynamic size).
    2. Supports row/col insert, erase, resize.
    3. All STL algorithms (sort, reverse, accumulate, count, max_element) work.
    4. Row-wise and column-wise operations are possible by iterating.
    5. Transpose can be built by swapping indices.
    6. Matrix can be flattened into 1D vector to use algorithms easily.
    7. Much safer and more flexible than raw 2D arrays.
    */

    return 0;
}
