#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<int> parent;
vector<int> level;

void make_set(int v) {
    parent[v] = v;
    level[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (level[a] < level[b])
            swap(a, b);
        parent[b] = a;
        if (level[a] == level[b])
            level[a]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    parent.resize(n);
    level.resize(n);
    // edges[e][0] = w
    // edges[e][1] = u
    // edges[e][2] = v
    vector<vector<ll>> edges;
    for (int i = 0; i < n; i++) {
        make_set(i);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v;
        cin >> w;
        // undirected edge u,v with weight w
        edges.push_back({w, u - 1, v - 1});
    }
    sort(edges.rbegin(), edges.rend());

    ll total = INT_MAX;
    for (vector<ll> edge : edges) {
        if (find_set(edge[1]) != find_set(edge[2])) {
            total = min(edge[0], total);
            union_sets(edge[1], edge[2]);
        }
    }

    cout << total;

}