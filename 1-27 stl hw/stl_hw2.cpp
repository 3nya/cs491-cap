#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <set>
#include <stack>
#include <unordered_map>
using namespace std;
typedef long long ll;
using vl = vector<ll>;

int main() {
    ll n;
    cin >> n;
    vl v;
    for (ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        v.push_back(temp);
    }
    stack<ll> s;
    stack<ll> index;

    vl result(v.size(), -2);
    // reverse
    for (ll i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= v[i]) {
            s.pop();
            index.pop();
        }
        if (!s.empty()) {
            result[i] = index.top();
        }
        s.push(v[i]);
        index.push(i);
    }
    for (int i = 0; i < v.size(); i++) {
        cout << result[i] + 1 << " ";
    }


}