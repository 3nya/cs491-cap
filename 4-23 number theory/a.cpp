#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

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

    int t;
    cin >> t;

    while (t--) {
        ll x, y;
        cin >> x >> y;

        if (gcd(x,y) == 1) {
            cout << (x * y) - x - y << "\n";
        } else {    
            cout << -1 << "\n";
        }
    }

}