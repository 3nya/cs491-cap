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

int phi(int n) {
    float result = n;

    // consider all prime factors of n for every prime factor p,
    // multiply result with (1-1/p)

    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }
            result *= (1.0 - (1.0 / (float) p));
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return (int) result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        cout << phi(n) << "\n";

    }
}