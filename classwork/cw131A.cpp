#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <iostream>
#include <deque>
#include <queue>
using namespace std;
typedef long long ll;
using vl = vector<ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, s;
    cin >> n >> s;
    vl v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }

    ll psum[n];
    psum[0] = v[0];
    for (int i = 1; i < n; i++) {
        psum[i] = v[i] + psum[i - 1];
    }

    ll left = 0;
    ll right = 0;
    ll count = 0;
    while (left < n) {
        ll sum = psum[right] - psum[left];
        if (left == 0) {
            sum = psum[right];
        }
        if (sum < s) {
            right++;
            count++;
        } else {
            left++;
            right = left;
        }
        if (right >= n) {
            left++;
            right = left;
        }
    }
    cout << count << endl;
    

}