#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;
        
        ll result = 1;
        while (k > 0) {
            if (k % 2 == 1) {
                result = (result * n) % MOD;
            }
            n = (n * n) % MOD;
            k /= 2;
        }
        
        
        cout << result << "\n";
    }



}