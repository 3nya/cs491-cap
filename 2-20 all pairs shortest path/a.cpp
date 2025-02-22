#pragma GCC optimize("O3,unroll-loops")
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

ll const INF = 1e9;
vector<vector<ll>> floyd_warshall(vector<vector<ll>> &arr, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] > (arr[i][k] + arr[k][j])) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    return arr;
}

// simple floyd warshall implementation to calculate all pairs shortest distance
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<ll>> arr;
    for (int i = 0; i < n; i++) {
        vector<ll> temparr;
        for (int j = 0; j < n; j++) {
            ll temp;
            cin >> temp;
            if (temp == 0) {
                temparr.push_back(INF);
            } else {
                temparr.push_back(temp);
            }
        }
        arr.push_back(temparr);
    }
    arr = floyd_warshall(arr, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << 0 << " ";
            } else {
                if (arr[i][j] >= INF) { // if unreachable print -1
                    cout << -1 << " ";
                } else {
                    cout << arr[i][j] << " ";
                }
            }
        }
        cout << "\n";
    }

}