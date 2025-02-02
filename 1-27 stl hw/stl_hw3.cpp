#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vl = vector<ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    vl v;
    for (ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        v.push_back(temp);
    }
    // value, index
    priority_queue<pair<ll, ll>> pq;

    ll prevLeft, prevRight;
    cin >> prevLeft >> prevRight;
    for (ll i = prevLeft - 1; i <= prevRight - 1; i++) {
        pq.push({v[i], i});
    }
    cout << pq.top().first << "\n";
    m--;
    while (m--) {
        ll left, right;
        cin >> left >> right;
        for (ll i = prevRight - 1; i <= right - 1; i++) {
            pq.push({v[i], i});
        }

        while (!pq.empty() && (pq.top().second < left - 1 || pq.top().second > right - 1)) {
            pq.pop();
        }
        prevLeft = left;
        prevRight = right;
        cout << pq.top().first << "\n";

    }
}