#pragma GCC optimize("O3,unroll-loops")
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, b1, b2;
    cin >> n >> b1 >> b2;

    if (n == 2) {
        cout << b1 + b2;;
    } else {
        int result = b1 | b2;
        cout << result << endl;
    }
}