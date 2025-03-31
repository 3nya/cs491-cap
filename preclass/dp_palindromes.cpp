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
    string str;
    cin >> n >> str;

    vector<vector<bool>> palindrome(n, vector<bool>(n, false));

    ll ans = 0;
    // all single characters
    for (int i = 0; i < n; i++) {
        palindrome[i][i] = true;
        ans++;
    }


    // all double characters
    for (int i = 0; i < n - 1; i++) {
        if (str[i] == str[i + 1]) {
            palindrome[i][i + 1] = true;
            ans++;
        }
    }


    // going through lenghts of the string 
    for (int length = 3; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            if (str[i] == str[i + length - 1] && palindrome[i + 1][i + length - 2]) {
                // if the border characters equal each other
                // and theres already a palindrome in between
                palindrome[i][i + length - 1] = true;
                ans++;
            }
        }
    }

    cout << ans << "\n";

}