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

struct edge {
    ll s, e, w, id;
    bool operator<(const struct edge& other) { return w < other.w; }
};
typedef struct edge Edge;

const ll N =  2e5 + 5;
ll n, m, a, b, w, id, l = 21;
vector<Edge> edges;
vector<ll> h(N, 0), parent(N, -1), sized(N, 0), present(N, 0);
// vi h(N, 0), parent(N, -1), size(N, 0), present(N, 0);
vector<vector<pair<ll,ll>>> adj(N), dp(N, vector<pair<ll, ll>>(l, {-1, -1}));
vector<vll> up(N, vector<ll>(l, -1));

pair<ll, ll> combine(pair<ll, ll> a, pair<ll, ll> b) {
    vector<ll> v = {a.first, a.second, b.first, b.second};
    ll topTwo = -3, topOne = -2;
    for (ll c : v) {
        if (c > topOne) {
            topTwo = topOne;
            topOne = c;
        } else if (c > topTwo && c < topOne) {
            topTwo = c;
        }
    }
    return {topOne, topTwo};
}

void dfs(ll u, ll par, ll d) {
    h[u] = 1 + h[par];
    up[u][0] = par;
    dp[u][0] = {d, -1};
    for (auto v : adj[u]) {
        if (v.first != par) {
            dfs(v.first, u, v.second);
        }
    }
}

pair<ll, ll> lca(ll u, ll v) {
    pair<ll, ll> ans = {-2, -3};
    if (h[u] < h[v]) {
        swap(u, v);
    }
    for (ll i = l - 1; i >= 0; i--) {
        if (h[u] - h[v] >= (1 << i)) {
            ans = combine(ans, dp[u][i]);
            u = up[u][i];
        }
    }
    if (u == v) {
        return ans;
    }
    for (ll i = l - 1; i >= 0; i--) {
        if (up[u][i] != -1 && up[v][i] != -1 && up[u][i] != up[v][i]) {
            ans = combine(ans, combine(dp[u][i], dp[v][i]));
            u = up[u][i];
            v = up[v][i];
        }
    }
    ans = combine(ans, combine(dp[u][0], dp[v][0]));
    return ans;
}

ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

ll union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sized[a] < sized[b]) {
            swap(a, b);
        }
        parent[b] = a;
        if (sized[a] == sized[b]) {
            sized[a]++;
        }
        return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (ll i = 1; i <= n; i++) {
        parent[i] = i;
        sized[i] = 1;
    }
    for (ll i = 1; i <= m; i++) {
        cin >> a >> b >> w;
        edges.push_back({a, b, w, i - 1});
    }
    ll res = 0;
    sort(edges.begin(), edges.end());
    for (ll i = 0; i <= m - 1; i++) {
        a = edges[i].s;
        b = edges[i].e;
        w = edges[i].w;
        id = edges[i].id;
        if (union_sets(a, b)) { 
            adj[a].emplace_back(b, w);
            adj[b].emplace_back(a, w);
            present[id] = 1;
            res += w;
        }
    }
    // cout << res << endl;
    dfs(1, 0, 0);
    for (ll i = 1; i <= l - 1; i++) {
        for (ll j = 1; j <= n; ++j) {
            if (up[j][i - 1] != -1) {
                ll v = up[j][i - 1];
                up[j][i] = up[v][i - 1];
                dp[j][i] = combine(dp[j][i - 1], dp[v][i - 1]);
            }
        }
    }

    ll ans = LLONG_MAX;
    for (ll i = 0; i <= m - 1; i++) {
        id = edges[i].id;
        w = edges[i].w;
        if (!present[id]) {
            auto rem = lca(edges[i].s, edges[i].e);
            if (ans > res + w - rem.first) {
                ans = res + w - rem.first;
            } else if (ans > res + w - rem.second) {
                ans = res + w - rem.second;
                
            } 
        }
    }
    cout << ans << "\n";
    return 0;



}