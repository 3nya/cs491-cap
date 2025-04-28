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


const ll mod = 998244353;

ll pow_mod(ll n, ll k) {
    if (k == 0) return 1;

    ll t = pow_mod(n, k / 2);
    if (k % 2 == 0) {
        return (t * t) % mod; 
    } else {
        return (((t * t) % mod) * n) % mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vll map(4000002); 
    ll curr = 1;
    for (int i = 1; i < 4000002; i++) {
        curr *= i;
        curr %= mod;
        map[i] = curr;
    }


    while (t--) {
        int n, k;
        cin >> n >> k;


        // unique numbers, order matters
        cout << (map[n] * pow_mod(map[n - k], mod - 2)) % mod << " ";

        // // unique numbers, order does not matter
        cout << (map[n] * pow_mod((map[n - k] * map[k]) % mod, mod - 2)) % mod << " ";

        // numbers may be repeated, order matters
        ll pow = pow_mod(n, k);

        cout << pow % mod << " ";

        // numbers may not be repeated, order doesnt matter
        cout << (map[n - 1 + k] * pow_mod((map[k] * map[n - 1]) % mod, mod - 2)) % mod << "\n";
    }
}