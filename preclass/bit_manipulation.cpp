#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;
    cout << __builtin_popcount(x) << endl;
}