#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;

vector<vector<int>> temples;
vector<int> color;
vector<bool> visited;

// checks all neighbors
bool isValid(int node, int c) {
    for (int neighbor : temples[node]) {
        if (color[neighbor] == c) {
            return false;
        }
    }
    return true;
}

bool dfs(int node, int k) {
    visited[node] = true;

    // try all possible colors for this node
    for (int c = 1; c <= k; c++) {
        if (isValid(node, c)) {
            color[node] = c;

            // checks all neighbors
            bool allNeighborsValid = true;
            for (int neighbor : temples[node]) {
                if (!visited[neighbor]) {
                    if (!dfs(neighbor, k)) {
                        allNeighborsValid = false;
                        break;
                    }
                }
            }

            if (allNeighborsValid) {
                return true;
            }
        }
    }


    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    temples.resize(n);
    color.resize(n, 0);
    visited.resize(n, false);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        temples[x].push_back(y);
        temples[y].push_back(x);
    }

    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (!dfs(i, k)) {
                possible = false;
                break;
            }
        }
    }

    if (possible) {
        for (int i = 0; i < n; i++) {
            cout << color[i] << "\n";
        }
    } else {
        cout << -1 << "\n";
    }
}