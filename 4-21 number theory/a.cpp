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

    vector<bool> v(n + 1, true);
    v[0] = false;
    v[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (v[i]) {
            for (ll j = i * i; j <= n; j += i) {
                v[j] = false;
            }
        }
    }

    int total = 0;
    for (int i = 2; i <= n; i++) {
        if (v[i]) {
            total++;
        }
    }
    cout << total << "\n";
    for (int i = 2; i <= n; i++) {
        if (v[i]) {
            cout << i << " ";
        }
    }
    cout << "\n"; 
}