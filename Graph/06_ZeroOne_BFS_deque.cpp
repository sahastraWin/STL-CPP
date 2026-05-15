#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

// 0-1 BFS using deque<int>
// Time: O(V + E), Space: O(V)
// Use: Shortest path when edge weights are ONLY 0 or 1
//      Faster than Dijkstra (O(V+E) vs O((V+E)logV)) for 0/1 weights
//
// Key idea:
//   Weight 0 edge → push to FRONT of deque (like it costs nothing)
//   Weight 1 edge → push to BACK of deque (normal cost)

int main()
{
    // --- Example 1: Grid with 0/1 cost ---
    cout << "=== Example 1: Basic 0-1 BFS ===\n";

    int n = 5;
    // adj[u] = {v, weight}  where weight is 0 or 1
    vector<vector<pair<int,int>>> adj(n);

    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    addEdge(0, 1, 0); // free edge
    addEdge(0, 2, 1);
    addEdge(1, 3, 1);
    addEdge(2, 3, 0); // free edge
    addEdge(3, 4, 1);

    int src = 0;
    vector<int> dist(n, INT_MAX);
    deque<int> dq;

    dist[src] = 0;
    dq.push_front(src);

    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (w == 0)
                    dq.push_front(v);  // weight 0 → front (higher priority)
                else
                    dq.push_back(v);   // weight 1 → back
            }
        }
    }

    cout << "Distances from node 0:\n";
    for (int i = 0; i < n; i++)
        cout << "  dist[" << i << "] = " << dist[i] << "\n";

    // --- Example 2: Grid problem (classic OA format) ---
    // Given a grid, cost to move to '.' is 0, cost to move to '#' is 1
    // Find minimum cost to reach bottom-right from top-left
    cout << "\n=== Example 2: Grid 0-1 BFS ===\n";

    vector<string> grid = {
        ".#...",
        ".###.",
        ".....",
        "###.#",
        ".....",
    };

    int rows = grid.size(), cols = grid[0].size();
    vector<vector<int>> gdist(rows, vector<int>(cols, INT_MAX));
    deque<pair<int,int>> gdq;

    gdist[0][0] = 0;
    gdq.push_front({0, 0});

    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};

    while (!gdq.empty()) {
        auto [x, y] = gdq.front();
        gdq.pop_front();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;

            int cost = (grid[nx][ny] == '#') ? 1 : 0;
            if (gdist[x][y] + cost < gdist[nx][ny]) {
                gdist[nx][ny] = gdist[x][y] + cost;
                if (cost == 0) gdq.push_front({nx, ny});
                else           gdq.push_back({nx, ny});
            }
        }
    }

    cout << "Min cost to reach bottom-right corner: "
         << gdist[rows-1][cols-1] << "\n";

    cout << "\nDistance grid:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (gdist[i][j] == INT_MAX) cout << "X ";
            else cout << gdist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
