#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
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

    int n;
    cin >> n;

    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // last val, indices
    map<int, int> seen;

    // parent, length of its subsequence
    map<int, int> parent;

    seen[v[0]] = 1;
    parent[v[0]] = 1;
    for (int i = 1; i < n; i++) {
        if (seen.count(v[i] - 1)) {
            seen[v[i]] = 1;
            parent[v[i]] = parent[v[i] - 1] + 1;
        } else {
            seen[v[i]] = 1; 
            parent[v[i]] = 1;
        }
    }

    int ans = 0;
    int ans_length = 0;
    for (auto& pair : parent) {
        if (pair.second > ans_length) {
            ans_length = pair.second;
            ans = pair.first;
        }
    }

    cout << ans_length << "\n";
    stack<int> stack;
    int curr = ans;
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] == curr) {
            stack.push(i);
            curr--;
        }
    }
    while (!stack.empty()) {
        cout << stack.top() + 1 << " ";
        stack.pop();
    }
    cout << "\n";


}