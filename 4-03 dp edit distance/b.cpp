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

// int d_strings(string s, int d) {
//     bool curr = false;
//     int count = 0;
//     int ans = 0;
//     for (int i = 0; i < s.length(); i++) {
//         if (s[i] == '1') {
//             if (curr) {
//                 count++;
//             } else {
//                 curr = true;
//                 count = 1;
//             }
//         } else {
//             curr = false;
//         }
//         if (count % d == 0) {
//             ans++;
//             count = 0;
//         }
//     }
//     return ans;
// }
int dp (string s, int k, int d) {
    vvi dp = vvi(s.length() + 1, vi(k + 1, 0));
    
    vi psum = vi(s.length() + 1, 0);

    psum[0] = 0;
    for (int i = 1; i <= s.length(); i++) {
        psum[i] = psum[i - 1] + (s[i - 1] == '0' ? 1 : 0);
    }
    for (int i = 1; i <= s.length(); i++) {
        for (int j = 0; j <= k; j++) {
            // skip this character
            dp[i][j] = dp[i - 1][j];

            // make a d-string
            if (i >= d) {
                int count = psum[i] - psum[i - d]; // previous complete d string
                if (count <= j) {
                    dp[i][j] = max(dp[i][j], dp[i - d][j - count] + 1);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = max(dp[s.length()][i], ans);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // non overlapping d-substrings
    int t;
    cin >> t;
    while (t--) {
        int k, d;
        string s;
        cin >> k >> d >> s;


        cout << dp(s, k ,d) << "\n";
    }

}