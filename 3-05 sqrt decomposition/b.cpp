// the number of distinct values of floor(k / i) is sqrt(k)

// so there will only be sqrt(k) blocks

// finding l and r for each block
// l = 1, r = k / (k / l)
// l++

// k mod i = k - i(floor(k/i))

#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <cmath>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
using vl = vector<ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k; 
    cin >> n >> k;

    ll result = 0;
    if (n > k) {
        result += k * (n - k);
        n = k;
    }
    ll i = 1;
    while (i <= n) {
        ll l = k / i;
        ll r = min(n, k / l);

        ll count = r - i + 1;
        ll sum = (ll)(i + r) * count / 2;
        result += k * count - l * sum;
        i = r + 1;
        // int l = i;
        // int r;
        // if (l > k) {
        //     r = n;
        // } else {
        //     r = (k / (k / l));
        // }

        // for (int j = l; j <= r; j++) {
        //     result += k - j * (k / j);
        // }

        // i = r;

    }
    cout << result << endl;
    
}