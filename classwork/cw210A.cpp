#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <iostream>
#include <deque>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using pi = pair<int, int>;

map<int, vi> temples;
map<int, int> color;
vector<bool> visited;
bool found = true;
void dfs(map<int, vi> map, int node, int prev_color, int k) {
    if (visited[node] || !found) {
        return;
    }
    visited[node] = true;
    vi connected = map[node];

    // visited before, ensure it doesn't have the same color as curr
    if (color.contains(node)) {
        if (color[node] == prev_color) {
            if (prev_color + 1 > k) {
                if (prev_color - 1 < 0) {
                    found = false;
                } else {
                    color[node]--;
                }
            } else {
                color[node]++;
            }
        }
    }


    for (int i = 0; i < connected.size(); i++) {
        dfs(map, connected[i], node, k);
    }

}
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, m, k;
    cin >> n >> m >> k;

    vii adj(n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        addEdge(adj, x, y);
    }

    for (int i = 0; i < n; i++) {
        // dfs on the node
    }

}