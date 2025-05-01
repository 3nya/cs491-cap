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

    int n, d;
    cin >> n >> d;

    int m;
    cin >> m;

    while (m--) {
        int x, y;
        cin >> x >> y;

        bool found = false;
        if (d - x <= y) {
            if (d + x >= y) {
                if (n + (n - d) - x >= y) {
                    if (-d + x <= y) {
                        cout << "YES" << "\n";
                        continue;
                    }
                }
            }
        }
        cout << "NO" << "\n";
    }

}
