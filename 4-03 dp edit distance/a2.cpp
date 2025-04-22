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
void dfs(vvi &dp, const vvi &v, int i, int j, int prev_i, int prev_j, int curr) {
    if (i < 0 || i >= dp.size()) {
        return;
    }
    if (j < 0 || j >= dp[0].size()) {
        return;
    }
    if (prev_i == -1 || prev_j == -1) {
    } else {
        if (v[i][j] <= v[prev_i][prev_j]) {
            return;
        }
        if (dp[i][j] > curr) {
            return;
        }
    }
    dp[i][j] = curr;

    for (vi direction : directions) {
        dfs(dp, v, i + direction[0], j + direction[1], i, j, curr + 1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vvi v(n, vi(m,0));
    dp.resize(n, vi(m,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dfs(dp, v, i, j, -1, -1, 1);
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
