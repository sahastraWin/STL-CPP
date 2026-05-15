#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <climits>
using namespace std;

// =============================================================
// MASTER GRAPH STL REFERENCE — for CP & Product Company OAs
// All representations + all STL tools in one file
// =============================================================

int main()
{
    cout << "========================================\n";
    cout << " GRAPH STL MASTER REFERENCE\n";
    cout << "========================================\n\n";

    // -------------------------------------------------------
    // 1. GRAPH REPRESENTATIONS
    // -------------------------------------------------------
    cout << "--- 1. Adjacency List (unweighted) ---\n";
    int n = 5;
    vector<vector<int>> adj(n);
    adj[0].push_back(1); adj[1].push_back(0);
    adj[0].push_back(2); adj[2].push_back(0);
    adj[1].push_back(3); adj[3].push_back(1);
    cout << "adj[0]: "; for (int x : adj[0]) cout << x << " "; cout << "\n";

    cout << "\n--- 2. Adjacency List (weighted) ---\n";
    vector<vector<pair<int,int>>> wadj(n); // {neighbor, weight}
    wadj[0].push_back({1, 5});
    wadj[1].push_back({0, 5});
    cout << "wadj[0]: {" << wadj[0][0].first << "," << wadj[0][0].second << "}\n";

    cout << "\n--- 3. Edge List with tuple ---\n";
    vector<tuple<int,int,int>> edges = {{3,0,1},{1,1,2},{2,0,2}};
    sort(edges.begin(), edges.end()); // sorts by weight (1st element)
    cout << "Sorted edges: ";
    for (auto [w,u,v] : edges) cout << u << "-" << v << "(" << w << ") ";
    cout << "\n";

    cout << "\n--- 4. Adjacency Matrix ---\n";
    vector<vector<int>> mat(4, vector<int>(4, 0));
    mat[0][1] = mat[1][0] = 1;
    mat[1][2] = mat[2][1] = 1;
    cout << "mat[0][1]=" << mat[0][1] << ", mat[0][2]=" << mat[0][2] << "\n";

    // -------------------------------------------------------
    // 2. BFS — queue<int>
    // -------------------------------------------------------
    cout << "\n--- 5. BFS using queue<int> ---\n";
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0); vis[0] = true;
    cout << "BFS: ";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v : adj[u])
            if (!vis[v]) { vis[v] = true; q.push(v); }
    }
    cout << "\n";

    // -------------------------------------------------------
    // 3. DFS — stack<int>
    // -------------------------------------------------------
    cout << "\n--- 6. DFS using stack<int> ---\n";
    vector<bool> vis2(n, false);
    stack<int> st;
    st.push(0);
    cout << "DFS: ";
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (vis2[u]) continue;
        vis2[u] = true;
        cout << u << " ";
        for (int v : adj[u])
            if (!vis2[v]) st.push(v);
    }
    cout << "\n";

    // -------------------------------------------------------
    // 4. DIJKSTRA — priority_queue (min-heap)
    // -------------------------------------------------------
    cout << "\n--- 7. Dijkstra using priority_queue (min-heap) ---\n";
    vector<vector<pair<int,int>>> dAdj(5);
    dAdj[0].push_back({1,2}); dAdj[1].push_back({0,2});
    dAdj[0].push_back({2,4}); dAdj[2].push_back({0,4});
    dAdj[1].push_back({2,1}); dAdj[2].push_back({1,1});
    dAdj[1].push_back({3,7}); dAdj[3].push_back({1,7});
    dAdj[2].push_back({4,3}); dAdj[4].push_back({2,3});

    vector<int> dist(5, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[0] = 0; pq.push({0,0});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v,w] : dAdj[u])
            if (dist[u]+w < dist[v]) { dist[v]=dist[u]+w; pq.push({dist[v],v}); }
    }
    cout << "Distances from 0: ";
    for (int i = 0; i < 5; i++) cout << dist[i] << " "; cout << "\n";

    // -------------------------------------------------------
    // 5. DIJKSTRA — set (decrease-key variant)
    // -------------------------------------------------------
    cout << "\n--- 8. Dijkstra using set<pair<int,int>> ---\n";
    vector<int> dist2(5, INT_MAX);
    set<pair<int,int>> sset;
    dist2[0]=0; sset.insert({0,0});
    while (!sset.empty()) {
        auto [d,u] = *sset.begin(); sset.erase(sset.begin());
        for (auto [v,w] : dAdj[u])
            if (dist2[u]+w < dist2[v]) {
                sset.erase({dist2[v],v});
                dist2[v]=dist2[u]+w;
                sset.insert({dist2[v],v});
            }
    }
    cout << "Distances from 0: ";
    for (int x : dist2) cout << x << " "; cout << "\n";

    // -------------------------------------------------------
    // 6. DSU + iota — Kruskal MST
    // -------------------------------------------------------
    cout << "\n--- 9. DSU with iota + Kruskal's MST ---\n";
    int nn = 4;
    vector<int> par(nn), rnk(nn,0);
    iota(par.begin(), par.end(), 0); // par[i]=i

    function<int(int)> find = [&](int x) {
        return par[x]==x ? x : par[x]=find(par[x]);
    };
    auto unite = [&](int x, int y) {
        x=find(x); y=find(y);
        if (x==y) return false;
        if (rnk[x]<rnk[y]) swap(x,y);
        par[y]=x;
        if (rnk[x]==rnk[y]) rnk[x]++;
        return true;
    };

    vector<tuple<int,int,int>> kEdges = {{1,0,1},{2,1,2},{3,0,2},{4,2,3}};
    sort(kEdges.begin(), kEdges.end());
    int mst=0;
    cout << "MST edges: ";
    for (auto [w,u,v] : kEdges)
        if (unite(u,v)) { mst+=w; cout<<u<<"-"<<v<<"("<<w<<") "; }
    cout << "\nMST cost: " << mst << "\n";

    // -------------------------------------------------------
    // 7. TOPOLOGICAL SORT — indegree + queue
    // -------------------------------------------------------
    cout << "\n--- 10. Topological Sort (Kahn's) ---\n";
    int tn=6;
    vector<vector<int>> tadj(tn);
    vector<int> indeg(tn,0);
    auto te=[&](int u,int v){ tadj[u].push_back(v); indeg[v]++; };
    te(5,2);te(5,0);te(4,0);te(4,1);te(2,3);te(3,1);

    queue<int> tq;
    for(int i=0;i<tn;i++) if(indeg[i]==0) tq.push(i);
    vector<int> topo;
    while(!tq.empty()){
        int u=tq.front();tq.pop();topo.push_back(u);
        for(int v:tadj[u]) if(--indeg[v]==0) tq.push(v);
    }
    cout << "Topo order: ";
    for(int x:topo) cout<<x<<" "; cout<<"\n";
    cout<<"Cycle? "<<((int)topo.size()!=tn?"Yes":"No")<<"\n";

    // -------------------------------------------------------
    // 8. 0-1 BFS — deque
    // -------------------------------------------------------
    cout << "\n--- 11. 0-1 BFS using deque ---\n";
    int on=5;
    vector<vector<pair<int,int>>> oadj(on);
    oadj[0].push_back({1,0}); oadj[1].push_back({0,0});
    oadj[0].push_back({2,1}); oadj[2].push_back({0,1});
    oadj[1].push_back({3,1}); oadj[3].push_back({1,1});
    oadj[2].push_back({3,0}); oadj[3].push_back({2,0});
    oadj[3].push_back({4,1}); oadj[4].push_back({3,1});

    vector<int> odist(on, INT_MAX);
    deque<int> dq;
    odist[0]=0; dq.push_front(0);
    while(!dq.empty()){
        int u=dq.front();dq.pop_front();
        for(auto[v,w]:oadj[u])
            if(odist[u]+w<odist[v]){
                odist[v]=odist[u]+w;
                if(w==0) dq.push_front(v);
                else dq.push_back(v);
            }
    }
    cout<<"0-1 BFS dist from 0: ";
    for(int x:odist) cout<<x<<" "; cout<<"\n";

    // -------------------------------------------------------
    // QUICK REFERENCE SUMMARY
    // -------------------------------------------------------
    cout << "\n========================================\n";
    cout << " QUICK REFERENCE\n";
    cout << "========================================\n";
    cout << "queue<int>                → BFS, Kahn's Topo Sort\n";
    cout << "stack<int>                → Iterative DFS\n";
    cout << "priority_queue (min-heap) → Dijkstra, Prim's MST\n";
    cout << "set<pair<int,int>>        → Dijkstra with decrease-key\n";
    cout << "deque<int>                → 0-1 BFS (weights 0 or 1)\n";
    cout << "unordered_map             → String/named node graphs\n";
    cout << "iota + vector             → DSU initialization\n";
    cout << "sort on tuple edges       → Kruskal's MST\n";
    cout << "vector<int> indegree      → Kahn's Topological Sort\n";
    cout << "vector<vector<int>>       → Adjacency list\n";
    cout << "vector<tuple<int,int,int>>→ Edge list\n";

    return 0;
}
