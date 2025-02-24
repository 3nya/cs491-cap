#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> order;
// and topological sort to detect cycles
bool bfs(vector<vector<int>>& adj, int n) {
    // stores in degrees of each vertex
    // in degrees are the number of edges directed into a specific vertex in a graph
    vector<int> inDegree(n, 0);

    int visited_nodes = 0;
    // Calculate in-degree of each vertex
    for (int u = 0; u < n; u++) {
        for (const auto v : adj[u]) {
            inDegree[v]++;
        }
    }
    queue<int> q;
    // Enqueue vertices with 0 in-degree
    for (int u = 0; u < n; u++) {
        if (inDegree[u] == 0) {
            q.push(u);
        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        visited_nodes++;
        order.push_back(x);

        for (int neighbor : adj[x]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    return visited_nodes == n;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(3 * n);


    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;

        int prev;
        cin >> prev;
        prev--;
        for (int j = 1; j < k; j++) {
            int temp;
            cin >> temp;
            temp--;
            adj[prev].push_back(temp);
            prev = temp;
        }
    }

    if (bfs(adj, 3 * n)) {
        cout << "YES";
        for (int i = 0; i < order.size(); i++) {
            if (i % 3 == 0) {
                cout << "\n";
            }
            cout << order[i] + 1 << " ";
        }
    } else {
        cout << "NO";
    }
}