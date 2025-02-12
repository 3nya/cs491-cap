#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <iostream>
using namespace std;

vector<int> color;
vector<vector<bool>> visited;

void dfs(vector<vector<char>> arr, int x, int y) {
    int directions[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    if (x < 0 || x >= arr.size() || y < 0 || y >= arr[0].size()) {
        return;
    }
    if (arr[x][y] == 'O') {
        return;
    }
    if (visited[x][y]) {
        return;
    }
    visited[x][y] = true;

    for (int* direction : directions) {
        dfs(arr, x + direction[0], y + direction[1]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr;
    visited.resize(n);

    for (int i = 0; i < n; i++) {
        visited[i].resize(m);
    }

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        vector<char> temp;
        for (int j = 0; j < m; j++) {
            temp.push_back(str[j]);
        }
        arr.push_back(temp);
    }

    int islands = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && arr[i][j] == 'L') {
                islands++;
                dfs(arr, i, j);
            }
        }
    }
    if (islands == 0) {
        cout << 0 << endl;
    } else {
        cout << islands - 1 << endl;
    }
}