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
    vll v;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        v.push_back(temp);
    }

    ll prev1 = 0;
    ll prev2 = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == n - 1) {
            ll temp = prev1;
            prev1 += v[i];
            prev2 = temp;
        } else {
            ll temp = prev1; 
            prev1 = max(prev1, prev2 + v[i]);
            prev2 = temp;
        }
    }
    cout << prev1 << "\n";

    // skip this jog: don't skip (i-1)
    // don't skip this jog: max( don't skip(i-1) , skip(i-1) ) + v[i]
}