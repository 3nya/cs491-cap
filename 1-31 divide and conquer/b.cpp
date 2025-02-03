#pragma GCC optimize("O3,unroll-loops")
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
using vl = vector<ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<pair<ll, ll>> v;
    for (ll i = 0; i < n; i++) {
        // seconds to finish, time its due
        ll d, t;
        cin >> d >> t;
        pair <ll, ll> p;
        p.first = d, p.second = t;
        v.push_back(p);
    }
    sort(v.begin(), v.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
        return a.second < b.second;
    });


    ll totalTimeTaken = 0;
    ll latestStartTime = 86400;
    // seconds to finish, time its due
    for (auto& [d, t] : v) {
        if (t < latestStartTime) {
            latestStartTime = t - d;
        } else {
            if (latestStartTime + d + totalTimeTaken > t) {
                latestStartTime -= (latestStartTime + totalTimeTaken + d) - t;
            }
        }
        if (latestStartTime < 0) {
            cout << -1 << endl;
            return 0;
        }
        totalTimeTaken += d;
    }

    if (totalTimeTaken > 86400) {
        cout << -1 << endl;
    } else {
        cout << latestStartTime << endl;
    }


}