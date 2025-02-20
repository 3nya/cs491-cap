#pragma GCC optimize("O3,unroll-loops")
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
ll flyod_warshall(vector<vector<int>> &arr, int n, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] > (arr[i][k] + arr[k][j])) {
                arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }

    ll dist = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            dist += arr[i][j];
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++) {
        vector<int> tempArr;
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            tempArr.push_back(temp);
        }
        arr.push_back(tempArr);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        if (cost < arr[a - 1][b - 1]) {
            arr[a - 1][b - 1] = cost;
            arr[b - 1][a - 1] = cost;
        }
        cout << min(flyod_warshall(arr, n, b - 1), flyod_warshall(arr, n, a - 1)) << " ";
    }
}