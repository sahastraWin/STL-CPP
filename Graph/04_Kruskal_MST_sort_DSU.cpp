#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
using namespace std;

// Kruskal's MST using sort on edge list + DSU initialized with iota
// Time: O(E log E), Space: O(V)
// Use: Minimum Spanning Tree, connecting components with min cost

// DSU (Disjoint Set Union / Union-Find)
struct DSU {
    vector<int> parent, rank_;

    DSU(int n) : parent(n), rank_(n, 0) {
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false; // already same component = would form cycle
        if (rank_[x] < rank_[y]) swap(x, y);
        parent[y] = x;
        if (rank_[x] == rank_[y]) rank_[x]++;
        return true;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

int main()
{
    int n = 5; // nodes 0 to 4
    // Edge list: {weight, u, v}
    vector<tuple<int,int,int>> edges = {
        {1, 0, 1},
        {3, 0, 2},
        {2, 1, 2},
        {4, 1, 3},
        {5, 2, 3},
        {6, 3, 4},
        {7, 2, 4}
    };

    // Sort by weight (first element of tuple) — sort works naturally on tuples
    sort(edges.begin(), edges.end());

    cout << "Edges sorted by weight:\n";
    for (auto [w, u, v] : edges)
        cout << "  " << u << " - " << v << " : " << w << "\n";

    DSU dsu(n);
    int mst_cost = 0;
    int edges_used = 0;

    cout << "\nKruskal's MST edges:\n";
    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) {
            mst_cost += w;
            edges_used++;
            cout << "  Added edge " << u << " - " << v << " with weight " << w << "\n";
            if (edges_used == n - 1) break; // MST has exactly n-1 edges
        } else {
            cout << "  Skipped edge " << u << " - " << v << " (would form cycle)\n";
        }
    }

    cout << "\nMST Total Cost: " << mst_cost << "\n";
    cout << "Edges used: " << edges_used << "\n";

    // Check connectivity
    cout << "\nAre nodes 0 and 4 connected? "
         << (dsu.connected(0, 4) ? "Yes" : "No") << "\n";

    // --- iota demo ---
    cout << "\n--- iota usage ---\n";
    vector<int> parent(6);
    iota(parent.begin(), parent.end(), 0); // fills: 0 1 2 3 4 5
    cout << "iota initialized parent array: ";
    for (int x : parent) cout << x << " ";
    cout << "\n";

    vector<int> indices(5);
    iota(indices.begin(), indices.end(), 1); // fills: 1 2 3 4 5
    cout << "iota from 1: ";
    for (int x : indices) cout << x << " ";
    cout << "\n";

    return 0;
}
