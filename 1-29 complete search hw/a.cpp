#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
using vl = vector<ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll l, r;
    cin >> l >> r;
    ll count = 0;
    for (ll i = l; i <= r; i++) {
        string s = to_string(i);
        if (s.find("495") != std::string::npos) {
            count++;
        }
    }
    cout << count << "\n";
}