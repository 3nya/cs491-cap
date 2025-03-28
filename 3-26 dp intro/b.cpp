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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vll a(n);
    vll b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<vll> dp(n, vector<ll>(3, 0));

    dp[0][0] = 0;
    dp[0][1] = a[0];
    dp[0][2] = b[0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                dp[i][j] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
            } else if (j == 1) {
                dp[i][j] = a[i] + max(dp[i - 1][0], dp[i - 1][2]);
            } else {
                dp[i][j] = b[i] + max(dp[i - 1][0], dp[i - 1][1]);
            }
        }
    }
    cout << max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << "\n";
}