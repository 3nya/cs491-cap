#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <bitset>
using namespace std;
using ll = long long;
const int MAX_N = 1000;

bitset<MAX_N> arr[MAX_N];
void floyd_warshall(int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (arr[i][k]) {  
                arr[i] |= arr[k]; 
            }
        }
    }
}

// simple floyd warshall implementation to calculate all pairs shortest distance
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            arr[i][j] = temp;
        }
    }
    floyd_warshall(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

}