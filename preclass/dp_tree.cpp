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

int n;
vvll DP;
vvi adj;
vector<bool> visited;
vll weights;
ll dfs(int u) {
    visited[u] = true;

    DP[u][0] = 0;   // UNINCLUDED
    DP[u][1] = weights[u]; // INCLDUED U

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
    // dp[][] = max(summation of child of dp[][], current weight + grandchild of dp[][])

            // exclude u, so we can use maximum of unincluded v or included v 
            DP[u][0] += max(DP[v][0], DP[v][1]); 

            // include u, so we have to use unincluded v
            DP[u][1] += DP[v][0];
        }
    }
    return max(DP[u][0], DP[u][1]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    adj.resize(n);
    DP.resize(n, vll(2, 0));
    weights.resize(n);
    visited.resize(n, false);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    
    cout << dfs(0) << "\n";

    // for (int i = 0; i < DP.size(); i++) {
    //     for (int j = 0; j < DP[i].size(); j++) {
    //         cout << DP[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}