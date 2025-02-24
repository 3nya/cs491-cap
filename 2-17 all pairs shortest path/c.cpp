#pragma GCC optimize("O3,unroll-loops")
#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
vector<vector<int>> adjlist;

void dfs(vector<vector<int>>& map, vector<bool>& visited, int original, int x) {
    if (visited[x]) {
        return;
    }
    visited[x] = true;

    for (int neighbor : map[x]) {
        adjlist[original][neighbor] = 1;
        dfs(map, visited, original, neighbor);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // node, other nodes it's directed towards
    vector<vector<int>> map(n);
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++) {
        vector<int> temp_arr;
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            if (temp == 1) {
                map[i].push_back(j);
            }
            temp_arr.push_back(temp);
        }
        arr.push_back(temp_arr);
    }
    adjlist = arr;
    for (int i = 0; i < n; i++) {
        vector<bool> visited(n, false);
        dfs(map, visited, i, i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjlist[i][j] << " ";
        }
        cout << "\n";
    }

}