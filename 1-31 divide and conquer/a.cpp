#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <iostream>
#include <cmath>
#include <valarray>
using namespace std;
typedef long long ll;
using vl = vector<ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll a, b;
    cin >> n >> a >> b;

    if (n == 0) {
        cout << "YES" << endl;
        return 0;
    }

    bool left = true;
    double prev_val = 1.0 / 3;  // Start with the first fraction
    for (int i = 1; i < n; i++) {
        double left_val, right_val;
        if (i == 1) {
            left_val = 1.0 / 3;
            right_val = 2.0 / 3;
        } else {
            if (left) {
                left_val = prev_val / 3;
                right_val = (prev_val / 3) * 2;
            } else {
                left_val = (prev_val / 3) * 2;
                right_val = (prev_val / 3) * 3;
            }
        }

        if ((left_val * b < a) && (right_val * b > a)) {
            cout << "YES" << endl;
            return 0;
        }

        if (left_val * b >= a) {
            left = true;
            prev_val = left_val;
        } else {
            left = false;
            prev_val = right_val;
        }
    }
    cout << "NO" << endl;

}