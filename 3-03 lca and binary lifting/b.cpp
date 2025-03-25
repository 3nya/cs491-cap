#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
vi parent;
vi level;

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
ll kruskal(int n, const vector<vll>& edges, vector<pair<int, int>>& mst_edges) {
    ll mst_cost = 0;
    mst_edges.clear();
    parent.resize(n);
    level.resize(n);
    for (int i = 0; i < n; i++) {
        make_set(i);
    }
    for (const auto& edge : edges) {
        int u = edge[1], v = edge[2];
        if (find_set(u) != find_set(v)) {
            mst_cost += edge[0];
            mst_edges.push_back({u, v});
            union_sets(u, v);
        }
    }
    return mst_cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vll> edges; 
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());


    vector<pair<int, int>> mst_edges;
    ll min = kruskal(n, edges, mst_edges);

    ll second_min = LLONG_MAX;
    for (vector<ll> skip_edge : edges) {
        vector<vll> new_edges;
        for (const auto& edge : edges) {
            if (!((edge[1] == skip_edge[1] && edge[2] == skip_edge[2]) ||
                  (edge[1] == skip_edge[2] && edge[2] == skip_edge[1]))) {
                new_edges.push_back(edge);
            }
        }
        for (const auto& edge : new_edges) {
            cout << edge[1] << " " << edge[2] << " " << edge[0] << endl;
        }
        vector<pair<int, int>> new_mst_edges;
        ll mst_cost = kruskal(n, new_edges, new_mst_edges);
        cout << mst_cost << endl;
        if (mst_cost > min && mst_cost < second_min) {
            second_min = mst_cost;
        }
    }
    cout << second_min << "\n";

}