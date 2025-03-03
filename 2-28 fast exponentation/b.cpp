#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <unordered_set>
using namespace std;
typedef long long ll;
using vl = vector<ll>;

const ll MOD = 998244353;

vector<vector<ll>> multiply(const vector<vector<ll>>& mat, const vector<vector<ll>>& mat2) {

    // [a, b, c]
    // [d, e, f]
    // [g, h, i]
    vector<vector<ll>> result(mat.size(), vector<ll>(mat.size(), 0));
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat.size(); j++) {
            ll sum = 0;
            for (int k = 0; k < mat.size(); k++) {
                sum += (mat[i][k] * mat2[k][j]);
                sum %= MOD;
            }
            result[i][j] = sum;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll k;
    cin >> k;

    if (k == 0) {
        cout << 4;
        return 0;
    } else if (k == 1) {
        cout << 9;
        return 0;
    } else if (k == 2) {
        cout << 5;
        return 0;
    }

    k -= 2;
    vector<vector<ll>> result = {{1,0,0}, {0,1,0}, {0,0,1}};
    vector<vector<ll>> n = {{5,9,4}, {1,0,0}, {0,1,0}};
    while (k > 0) {
        if (k % 2 == 1) {
            result = multiply(result, n);
        }
        n = multiply(n, n);
        k /= 2; 
    }

    vector<vector<ll>> temp = {{5, 0, 0}, {9, 0, 0}, {4, 0, 0}};
    result = multiply(result, temp);
    
    cout << result[0][0] << "\n";
    
}