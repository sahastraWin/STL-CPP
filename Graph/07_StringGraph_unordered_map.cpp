#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

// Graphs with String/Non-Integer nodes using unordered_map
// Time: O(V + E) for BFS/DFS, O((V+E)logV) for Dijkstra
// Use: Word ladder, city networks, dependency graphs with named nodes

int main()
{
    // --- Example 1: City graph with string nodes ---
    cout << "=== Example 1: BFS on City Graph ===\n";

    unordered_map<string, vector<string>> adj;

    auto addEdge = [&](string u, string v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addEdge("Mumbai", "Pune");
    addEdge("Mumbai", "Surat");
    addEdge("Pune", "Nashik");
    addEdge("Surat", "Ahmedabad");
    addEdge("Nashik", "Aurangabad");

    string src = "Mumbai";
    unordered_map<string, bool> visited;
    unordered_map<string, int> dist;
    unordered_map<string, string> parent;

    queue<string> q;
    q.push(src);
    visited[src] = true;
    dist[src] = 0;

    cout << "BFS from " << src << ": ";
    while (!q.empty()) {
        string city = q.front(); q.pop();
        cout << city << " ";

        for (const string& nb : adj[city]) {
            if (!visited[nb]) {
                visited[nb] = true;
                dist[nb] = dist[city] + 1;
                parent[nb] = city;
                q.push(nb);
            }
        }
    }

    cout << "\n\nDistances from Mumbai:\n";
    for (auto& [city, d] : dist)
        cout << "  " << city << " = " << d << " hops\n";

    // Reconstruct path
    cout << "\nPath Mumbai → Aurangabad: ";
    vector<string> path;
    for (string v = "Aurangabad"; v != ""; v = parent.count(v) ? parent[v] : "")
        path.push_back(v);
    reverse(path.begin(), path.end());
    for (const string& s : path) cout << s << " → ";
    cout << "END\n";

    // --- Example 2: Weighted city graph using Dijkstra ---
    cout << "\n=== Example 2: Dijkstra on Weighted String Graph ===\n";

    unordered_map<string, vector<pair<string,int>>> wadj; // {neighbor, weight}

    auto addWEdge = [&](string u, string v, int w) {
        wadj[u].push_back({v, w});
        wadj[v].push_back({u, w});
    };

    addWEdge("A", "B", 4);
    addWEdge("A", "C", 2);
    addWEdge("B", "D", 3);
    addWEdge("C", "B", 1);
    addWEdge("C", "D", 5);
    addWEdge("D", "E", 1);

    string start = "A";
    unordered_map<string, int> sdist;
    for (auto& [node, _] : wadj) sdist[node] = INT_MAX;
    sdist[start] = 0;

    // Min heap: {dist, node}
    priority_queue<pair<int,string>,
                   vector<pair<int,string>>,
                   greater<pair<int,string>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > sdist[u]) continue;

        for (auto [v, w] : wadj[u]) {
            if (sdist[u] + w < sdist[v]) {
                sdist[v] = sdist[u] + w;
                pq.push({sdist[v], v});
            }
        }
    }

    cout << "Shortest distances from A:\n";
    for (auto& [node, d] : sdist)
        cout << "  " << node << " = " << d << "\n";

    // --- Example 3: Word Ladder (classic OA problem) ---
    cout << "\n=== Example 3: Word Ladder (BFS) ===\n";
    // Find min transformations: hit → cog
    // Each step: change one letter, result must be in word list

    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit", endWord = "cog";

    unordered_map<string, bool> wordSet;
    for (auto& w : wordList) wordSet[w] = true;

    queue<pair<string,int>> wq; // {word, steps}
    wq.push({beginWord, 1});
    unordered_map<string, bool> wvisited;
    wvisited[beginWord] = true;

    int result = 0;
    while (!wq.empty()) {
        auto [word, steps] = wq.front(); wq.pop();
        if (word == endWord) { result = steps; break; }

        for (int i = 0; i < (int)word.size(); i++) {
            string next = word;
            for (char c = 'a'; c <= 'z'; c++) {
                next[i] = c;
                if (wordSet.count(next) && !wvisited[next]) {
                    wvisited[next] = true;
                    wq.push({next, steps + 1});
                }
            }
        }
    }

    cout << "Word Ladder length (" << beginWord << " → " << endWord << "): "
         << result << "\n"; // Expected: 5

    return 0;
}
