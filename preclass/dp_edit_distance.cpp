#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int ld (string s, int len_s, string t, int len_t) {
    vvi dp = vvi(len_s + 1, vi(len_t + 1));
    int cost;
    for (int i = 1; i <= len_s; ++i) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= len_t; ++i) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= len_s; i++) {
        for (int j = 1; j <= len_t; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
            }
        }
    }
    return dp[len_s][len_t]; // the answer will be in the last cell of the matrix
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t; 

    cout << ld(s, s.length(), t, t.length()) << "\n";

}