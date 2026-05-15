#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS - Breadth First Search using queue<int>
// Time: O(V + E), Space: O(V)
// Use: Shortest path in unweighted graph, level-order traversal

int main()
{
    int n = 6; // nodes 0 to 5
    vector<vector<int>> adj(n);

    // Build undirected graph
    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 5);
    addEdge(4, 5);

    int src = 0;
    vector<bool> visited(n, false);
    vector<int> dist(n, -1); // distance from source

    queue<int> q;
    q.push(src);
    visited[src] = true;
    dist[src] = 0;

    cout << "BFS traversal from node " << src << ": ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    cout << "\n\nShortest distances from node " << src << ":\n";
    for (int i = 0; i < n; i++)
        cout << "  dist[" << i << "] = " << dist[i] << "\n";

    return 0;
}
