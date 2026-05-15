#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Dijkstra's Shortest Path using priority_queue (min-heap)
// Time: O((V + E) log V), Space: O(V)
// Use: Shortest path in weighted graph with NON-NEGATIVE weights

int main()
{
    int n = 6; // nodes 0 to 5
    vector<vector<pair<int,int>>> adj(n); // adj[u] = {v, weight}

    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected
    };

    addEdge(0, 1, 2);
    addEdge(0, 2, 4);
    addEdge(1, 2, 1);
    addEdge(1, 3, 7);
    addEdge(2, 4, 3);
    addEdge(3, 5, 1);
    addEdge(4, 3, 2);
    addEdge(4, 5, 5);

    int src = 0;
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1); // to reconstruct path

    // MIN heap: pair<distance, node>
    // Default pq is MAX heap, so use greater<> for MIN heap
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src}); // {distance, node}

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // Lazy deletion: skip stale entries
        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "  dist[" << i << "] = ";
        if (dist[i] == INT_MAX) cout << "INF";
        else cout << dist[i];
        cout << "\n";
    }

    // Reconstruct path from src to node 5
    cout << "\nPath from 0 to 5: ";
    vector<int> path;
    for (int v = 5; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    for (int x : path) cout << x << " ";
    cout << "\n";

    // --- Dijkstra using set (supports true decrease-key) ---
    cout << "\n--- Dijkstra using set<pair<int,int>> ---\n";
    vector<int> dist2(n, INT_MAX);
    set<pair<int,int>> st; // {dist, node}

    dist2[src] = 0;
    st.insert({0, src});

    while (!st.empty()) {
        auto [d, u] = *st.begin(); // smallest dist
        st.erase(st.begin());

        for (auto [v, w] : adj[u]) {
            if (dist2[u] + w < dist2[v]) {
                st.erase({dist2[v], v}); // remove old — true decrease-key
                dist2[v] = dist2[u] + w;
                st.insert({dist2[v], v});
            }
        }
    }

    cout << "Distances: ";
    for (int i = 0; i < n; i++) cout << dist2[i] << " ";
    cout << "\n";

    return 0;
}
