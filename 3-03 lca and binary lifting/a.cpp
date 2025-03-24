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

struct Node {
    int val;
    // Node, weight of path
    vector<pair<Node*, ll>> children;
};
const int MAX_N = 100001;
const int LOG = 20;
int n;
vector<Node> nodes;
vector<vector<Node*>> up(MAX_N, vector<Node*>(LOG));
vector<vector<ll>> dist(MAX_N, vector<ll>(LOG));
vector<int> depth(MAX_N);

void dfs(Node* u, Node* parent, ll path_weight) {
    up[u->val][0] = parent;  // Direct ancestor
    dist[u->val][0] = path_weight;

    for (int k = 1; k < LOG; ++k) {
        if (up[u->val][k - 1] != nullptr) {
            up[u->val][k] = up[up[u->val][k - 1]->val][k - 1];
            dist[u->val][k] = dist[u->val][k - 1] + dist[up[u->val][k - 1]->val][k - 1];
        } else {
            break;
        }
    }

    for (auto& child : u->children) {
        if (child.first != parent) {
            depth[child.first->val] = depth[u->val] + 1;
            dfs(child.first, u, child.second);
        }
    }
}
pair<Node*, ll> lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);  // ensure a is deeper or at same level as b

    ll total_weight = 0;
    // Bring a and b to the same depth
    for (int i = LOG - 1; i >= 0; --i) {
        if (depth[a] - (1 << i) >= depth[b]) {
            total_weight += dist[a][i];
            a = up[a][i]->val;
        }
    }

    if (a == b) return {&nodes[a], total_weight};

    for (int i = LOG - 1; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            total_weight += dist[a][i] + dist[b][i];
            a = up[a][i]->val;
            b = up[b][i]->val;
        }
    }

    total_weight += dist[a][0] + dist[b][0];  // Adding the last step to the LCA
    return {up[a][0], total_weight};
    // cout << "lca called with " << a << " " << b << " " << curr << endl;
    // if (root == nullptr || root->val == a || root->val == b) {
    //     return {root, curr};
    // }

    // pair<Node*, ll> temp;
    // for (pair<Node*, ll> child : root->children) {
    //     pair<Node*, ll> result = lca(child.first, a, b, curr + child.second);

    //     if (result.first != nullptr) {
    //         temp = result; 
    //     }
    // }   
    
    // if (temp.first != nullptr) {
    //     cout << "value: " << temp.second << endl;
    //     return temp;
    // }
    // return {nullptr, 0};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m; 

    nodes.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        nodes[i].val = i;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        nodes[u].children.push_back({&nodes[v], w});
        nodes[v].children.push_back({&nodes[u], w});
    }

    depth[1] = 0;
    dfs(&nodes[1], nullptr, 0);

    ll total = 0;
    int prev = 1;
    while (m--) {
        int a;
        cin >> a;

        pair<Node*, ll> temp = lca(prev, a);

        total += temp.second;
        prev = a;
    }
    pair<Node*, ll> temp = lca(prev, 1);
    total += temp.second;
    cout << total << "\n";
}