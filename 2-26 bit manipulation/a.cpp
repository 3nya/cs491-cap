#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    if (__builtin_popcount(n) > k || k > n) {
        cout << "NO";
    } else {
        priority_queue<int> coins;

        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                coins.push(1 << i);
            }
        }

        int amount = coins.size();
        while (amount < k) {
            int largest = coins.top();
            coins.pop();
    
            if (largest == 1) {
                cout << "NO";
                return 0;
            }
    
            coins.push(largest / 2);
            coins.push(largest / 2);
            amount++;
        }

        if (amount != k) {
            cout << "NO";
            return 0;
        }
        cout << "YES" << "\n";
        vector<int> result;
        while (!coins.empty()) {
            result.push_back(coins.top());
            coins.pop();
        }
        for (int i = result.size() - 1; i >= 0; i--) {
            cout << result[i] << " ";
        }
    }
}