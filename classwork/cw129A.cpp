#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <unordered_set>
using namespace std;
typedef long long ll;
using vl = vector<ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vl v;
        unordered_set<ll> s;
        for (ll i = 0; i < n; i++) {
            ll temp;
            cin >> temp;
            v.push_back(temp);
            s.insert(temp);
        }

        for (ll i = 0; i < n; i++) {

        }
    }
}