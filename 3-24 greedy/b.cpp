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

    int n, k;
    cin >> n >> k;

    vi c(n);
    vi p(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int coins = 0;
    double time = 0;
    // k / p_i + c_i < k

    // time if not taking - k / p'
    // time if took       - c_i/p' + k/p'*p_i

    // whether you take an upgrade or not, it has nothing to do with the current
    // production speed

    // k > c_i + k/p_i

    // after we find what upgrades we want, we need to find whats the optimal sequence
    // of taking them

    // upgrade i: p_i, c_i
    // upgrade j: p_j, c_j

    // sort based on this
    // c_i + (c_j/p_i) < c_j + (c_i/p_j)

    // for (int i = 0; i < n; i++) {
    //     if ()
    // }
}