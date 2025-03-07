#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <cmath>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
using vl = vector<ll>;

int n;
// index is the node, pair is node, color
vector<vector<pair<int, int>>> graph;
vector<int> color;
vector<bool> visited;

bool dfs(int node, int val) {
    visited[node] = true;
    color[node] = val;

    for (auto [neighbor, weight] : graph[node]) {
        if (!visited[neighbor]) {
            if (!dfs(neighbor, val ^ weight)) return false;
        } else if (color[neighbor] != (val ^ weight)) {
            return false; 
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;
    color.resize(n, -1);
    graph.resize(n);
    visited.resize(n, false);
    while (m--) {
        char c1, c2, c3;
        string temp;
        int a, b, k;
        cin >> c1 >> a >> temp >> c2 >> b >> c3 >> k;
        graph[a - 1].push_back({b - 1, k});
        graph[b - 1].push_back({a - 1, k});  

    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (!dfs(i, 0)) {
                cout << "NO" << "\n";
                return 0;
            }
        }
    }
    cout << "YES" << "\n";
}