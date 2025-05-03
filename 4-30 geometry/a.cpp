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

    int n;
    cin >> n;
    
    // first = x
    // second = y
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        cin >> v[i].second;
    }

    ll lsum = 0;
    ll rsum = 0;
    for (int i = 0; i < n - 1; i++) {
        lsum += v[i].first * v[i + 1].second;
        rsum += v[i].second * v[i + 1].first;
    }
    lsum += v[n - 1].first * v[0].second;
    rsum += v[n - 1].second * v[0].first;

    cout << setprecision(30) << .5 * abs(lsum - rsum) << "\n";
}