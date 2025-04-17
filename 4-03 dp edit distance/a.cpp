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

vvi dp;
vvi directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
void bfs(vvi &dp, const vvi &v, int i, int j) {
    queue<pii> q;
    q.push({i, j}); // visited

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int new_dist = dp[x][y] + 1;

        for (vi direction : directions) {
            int new_x = x + direction[0];
            int new_y = y + direction[1];
            if (new_x < 0 || new_x >= dp.size() || new_y < 0 || new_y >= dp[0].size()) {
                continue;
            }
            if (dp[new_x][new_y] >= new_dist) {
                continue;
            }
            if (v[new_x][new_y] <= v[x][y]) {
                continue;
            }
            dp[new_x][new_y] = new_dist;
            q.push({new_x, new_y});

        }
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vvi v(n, vi(m,0));
    dp.resize(n, vi(m,1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bfs(dp, v, i, j);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m;j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
}
