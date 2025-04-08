#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
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

    int n, k;
    cin >> n >> k;

    vi c(n);
    vi p(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vi upgrades;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        
        if (k / p[i] + c[i] < k) {
            upgrades.push_back(i);
        }
    }

    sort(upgrades.begin(), upgrades.end(), [&](int i, int j) {
        double left = c[i] + static_cast<double>(c[j]) / p[i];
        double right = c[j] + static_cast<double>(c[i]) / p[j];
        return left < right;
    });

    double time = 0;
    double multipler = 1;
    for (int i = 0; i < upgrades.size(); i++) {
        time += c[upgrades[i]] / multipler;
        multipler *= p[upgrades[i]];
    }
    
    time += k / multipler; 
    cout << setprecision(7) << time << "\n";
    // for (int i = 0; i < upgrades.size(); i++) {
    //     cout << upgrades[i] + 1 << " ";
    // }
    // cout << "\n";
    // double time = 0;
    // double mulitplier = 1;
    // int coins = 0;
    // for (int i = 0; i < upgrades.size(); i++) {
    //     if (((c[upgrades[i]] - coins) / mulitplier) < ((k - coins) /  mulitplier)) {

    //     } else {
    //         break;
    //     }
    //     if (coins >= k) {
    //         break;
    //     } else {
    //         // time to get to next upgrade, or total amount of coins (if that is less time)
    //         // add = min((c[upgrades[i]] - coins) / mulitplier, (k - coins) /  mulitplier);

    //         if (coins >= c[upgrades[i]]) {
    //             add = (c[upgrades[i]] - coins) / mulitplier;
    //             coins -= c[upgrades[i]];
    //         } else {
    //             if (((c[upgrades[i]] - coins) / mulitplier) < ((k - coins) /  mulitplier)) {
    //                 add = c[upgrades[i]] - coins;
    //                 coins -= c[upgrades[i]];

    //                 time += add;
    //                 coins += add * mulitplier;
    //                 mulitplier += p[upgrades[i]];

    //             } else {
    //                 add = (k - coins) /  mulitplier;
    //                 time += add;
    //                 break;
    //             }
    //         }
    //     }
    // }
    // if (coins < k) {
    //     time += (k - coins) / mulitplier;
    // }

    // k / p_i + c_i < k

    // time if not taking - k / p'
    // time if took       - c_i/p' + k/p'*p_i

    // whether you take an upgrade or not, it has nothing to do with the current
    // production speed

    // k > c_i + k/p_i

    // after we find what upgrades we want, we need to find whats the optimal sequence
    // of taking them

    // upgrade i: p_i, c_i
    // upgrade j: p_j, c_j

    // sort based on this
    // c_i + (c_j/p_i) < c_j + (c_i/p_j)


}