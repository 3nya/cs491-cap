#pragma GCC optimize("O3,unroll-loops")
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> tin; // tin[v] = entry time for node v
vector<int> low; // low[v] = min(tin[v], tin[p] (for all p which v is connected to), low[to] for all vertex to
                 // that is a direct descendant of p

// there is a back edge from vertex v if low[to] < tin[v]
// if low[to] = tin[v], the back edge comes directly to v
// vertex v in the DFS tree is an articulation point only if low[to] >= tin[v]

int timer;

set<int> cutpoints;
void IS_CUTPOINT(int v) {
    cutpoints.insert(v);
}

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++; // time it was visited
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                IS_CUTPOINT(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        IS_CUTPOINT(v);
}
void find_cutpoints() {
    timer = 0;
    cutpoints.clear();
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;

    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    find_cutpoints();

    cout << cutpoints.size() << "\n";
    for (const int& element : cutpoints) {
        cout << element + 1 << " ";
    }
}