#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Topological Sort using Kahn's Algorithm
// STL: vector<int> indegree + queue<int>
// Time: O(V + E), Space: O(V)
// Use: Task scheduling, build order, course prerequisites
// Bonus: Also detects cycles (if topo.size() != n, cycle exists)

int main()
{
    // --- Example 1: Simple DAG ---
    cout << "=== Example 1: Course Prerequisites ===\n";
    // Courses: 0=Math, 1=Physics, 2=Chemistry, 3=Biology, 4=CS, 5=AI
    // Edge u->v means: must take u before v
    int n = 6;
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        indegree[v]++;
    };

    addEdge(0, 2); // Math → Chemistry
    addEdge(0, 4); // Math → CS
    addEdge(1, 2); // Physics → Chemistry
    addEdge(1, 4); // Physics → CS
    addEdge(2, 3); // Chemistry → Biology
    addEdge(4, 5); // CS → AI

    // Push all nodes with indegree 0 into queue first
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) // all prerequisites done
                q.push(v);
        }
    }

    if ((int)topo.size() != n) {
        cout << "Cycle detected! No valid topological order.\n";
    } else {
        cout << "Topological Order: ";
        for (int x : topo) cout << x << " ";
        cout << "\n";
        // Multiple valid orders possible — this gives one of them
    }

    // --- Example 2: Cycle detection ---
    cout << "\n=== Example 2: Cycle Detection ===\n";
    int n2 = 4;
    vector<vector<int>> adj2(n2);
    vector<int> indegree2(n2, 0);

    auto addEdge2 = [&](int u, int v) {
        adj2[u].push_back(v);
        indegree2[v]++;
    };

    addEdge2(0, 1);
    addEdge2(1, 2);
    addEdge2(2, 3);
    addEdge2(3, 1); // creates cycle: 1 → 2 → 3 → 1

    queue<int> q2;
    for (int i = 0; i < n2; i++)
        if (indegree2[i] == 0)
            q2.push(i);

    vector<int> topo2;
    while (!q2.empty()) {
        int u = q2.front(); q2.pop();
        topo2.push_back(u);
        for (int v : adj2[u]) {
            indegree2[v]--;
            if (indegree2[v] == 0) q2.push(v);
        }
    }

    if ((int)topo2.size() != n2)
        cout << "Cycle detected! (processed " << topo2.size() << " of " << n2 << " nodes)\n";
    else
        cout << "No cycle found.\n";

    // --- Example 3: Priority queue variant (lexicographically smallest topo order) ---
    cout << "\n=== Example 3: Lexicographically Smallest Topo Order ===\n";
    int n3 = 4;
    vector<vector<int>> adj3(n3);
    vector<int> indegree3(n3, 0);

    auto addEdge3 = [&](int u, int v) {
        adj3[u].push_back(v);
        indegree3[v]++;
    };

    addEdge3(0, 1);
    addEdge3(0, 2);
    addEdge3(3, 1);
    addEdge3(3, 2);

    // Use min priority_queue instead of regular queue
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n3; i++)
        if (indegree3[i] == 0)
            pq.push(i);

    vector<int> topo3;
    while (!pq.empty()) {
        int u = pq.top(); pq.pop();
        topo3.push_back(u);
        for (int v : adj3[u]) {
            indegree3[v]--;
            if (indegree3[v] == 0) pq.push(v);
        }
    }

    cout << "Lexicographically smallest topo order: ";
    for (int x : topo3) cout << x << " ";
    cout << "\n";

    return 0;
}
