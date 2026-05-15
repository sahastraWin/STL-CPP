#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// DFS - Depth First Search using stack<int> (iterative)
// Also shows recursive DFS for comparison
// Time: O(V + E), Space: O(V)
// Use: Cycle detection, connected components, path finding

int n = 6;
vector<vector<int>> adj;
vector<bool> vis;

// Recursive DFS
void dfs_recursive(int node) {
    vis[node] = true;
    cout << node << " ";
    for (int nb : adj[node])
        if (!vis[nb])
            dfs_recursive(nb);
}

int main()
{
    n = 6;
    adj.assign(n, {});
    vis.assign(n, false);

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

    // --- Iterative DFS using stack ---
    cout << "Iterative DFS from node 0: ";
    vector<bool> visited(n, false);
    stack<int> st;
    st.push(0);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (visited[node]) continue;
        visited[node] = true;
        cout << node << " ";

        // Push neighbors in reverse to match recursive order
        for (int i = adj[node].size() - 1; i >= 0; i--)
            if (!visited[adj[node][i]])
                st.push(adj[node][i]);
    }

    // --- Recursive DFS ---
    cout << "\nRecursive DFS from node 0: ";
    dfs_recursive(0);

    // --- Count connected components ---
    cout << "\n\nCounting connected components:\n";
    vector<vector<int>> adj2(7);
    // Component 1: 0-1-2
    adj2[0].push_back(1); adj2[1].push_back(0);
    adj2[1].push_back(2); adj2[2].push_back(1);
    // Component 2: 3-4
    adj2[3].push_back(4); adj2[4].push_back(3);
    // Component 3: 5-6
    adj2[5].push_back(6); adj2[6].push_back(5);

    vector<bool> vis2(7, false);
    int components = 0;
    for (int i = 0; i < 7; i++) {
        if (!vis2[i]) {
            components++;
            stack<int> s;
            s.push(i);
            while (!s.empty()) {
                int u = s.top(); s.pop();
                if (vis2[u]) continue;
                vis2[u] = true;
                for (int v : adj2[u])
                    if (!vis2[v]) s.push(v);
            }
        }
    }
    cout << "Number of connected components: " << components << "\n"; // 3

    return 0;
}
