#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <cmath>
#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <unordered_set>
using namespace std;
typedef long long ll;
using vl = vector<ll>;

// lookup[i][j] is going to store the maximum
// value in arr[i..j]
vector<vector<ll>> lookup;
void buildSparseTable(vl &arr, int n) {
    int maxJ = log2(n) + 1;
    lookup.assign(n, vector<ll>(maxJ));
    
    for (int i = 0; i < n; i++) {
        lookup[i][0] = arr[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; (i + (1 << j) - 1) < n; i++) {

            if (lookup[i][j - 1] > lookup[i + (1 << (j - 1))][j - 1])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j] = lookup[i + (1 << (j - 1))][j - 1];
        }
    }
}

int query(int L, int R) {
    int j = (int) log2(R - L + 1);
    if (lookup[L][j] >= lookup[R - (1 << j) + 1][j])
        return lookup[L][j];
 
    else
        return lookup[R - (1 << j) + 1][j];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vl arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    buildSparseTable(arr, n);
    int l, r, s;
    cin >> l >> r >> s;

    ll total = 0;
    for (int i = 0; i < m; i++) {
        // cout << "max value: " << query(l - 1, r - 1) << endl;
        total += query(l - 1, r - 1);
        l = (l + s) % n + 1;
        r = (r + s) % n + 1;
        if (l > r) {
            swap(l, r);
        }
        // cout << "Left: " << l << " Right: " << r << endl;
    }
    cout << total << endl;

}