#pragma GCC optimize("O3,unroll-loops")
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
using ll = long long;

struct Edge {
    int a, b;
    ll cost;
};

int n, m;
vector<Edge> edges;
const ll INF = 1e19;

void solve() {
    vector<ll> d(n, 0);
    vector<int> p(n, -1);
    int x = -1;
    d[0] = 0;

    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] < INF && d[e.a] + e.cost < d[e.b]) {
                d[e.b] = max(-INF, d[e.a] + e.cost);
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }
    if (x == -1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

// bellman ford detect negative cycles
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin.ignore();

    for (int i = 0; i < m; i++) {
        string s;
        getline(cin, s);

        stringstream ss(s);
        string xa, xb, sign;
        int a, b;
        ll weight;

        ss >> xa >> sign >> xb >> sign >> weight;

        a = stoi(xa.substr(1)) - 1;
        b = stoi(xb.substr(1)) - 1;

        edges.push_back({a, b, weight});
    }
    solve();
    return 0;
}