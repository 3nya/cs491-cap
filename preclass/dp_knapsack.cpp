#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    vi a(n);
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vi f(t + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = t; j >= a[i]; j--) {
            f[j] = max(f[j], f[j - a[i]] + v[i]);
        }
    }
    cout << f[t] << "\n";
}