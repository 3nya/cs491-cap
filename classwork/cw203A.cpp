#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q, l;
    cin >> n >> q >> l;
    vl v;
    bool consecutive = false;
    int count = 0;
    for (ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        v.push_back(temp);
        if (v[i] > l) {
            if (!consecutive) {
                consecutive = true;
                count++;
            }
        } else {
            consecutive = false;
        }
    }
    for (ll i = 0; i < q; i++) {
        int c;
        cin >> c;
        if (c == 0) {
            cout << count << "\n";
        } else {
            ll ind, len;
            cin >> ind >> len;
            ind--;
            bool was_in_segment = (v[ind] > l);
            v[ind] += len;
            bool is_in_segment = (v[ind] > l);

            if (!was_in_segment && is_in_segment) {
                bool left = (ind > 0 && v[ind - 1] > l);
                bool right = (ind < n - 1 && v[ind + 1] > l);

                if (left && right) {
                    count--;
                } else if (!left && !right) {
                    count++;
                }
            }

        }
    }
}