#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
typedef long long ll;
using vi = vector<int>;

int main() {
    ll n;
    cin >> n;
    ll v[n];
    for (int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        v[i] = temp;
    }
    ll psum[n];
    psum[0] = v[0];
    for (int i = 1; i < n; i++) {
        psum[i] = v[i] + psum[i - 1];
    }
    ll ans = 0;
    ll minpsum = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, psum[i] - minpsum);
        minpsum = min(minpsum, psum[i]);
    }
    cout << ans << endl;
}