#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <variant>
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vi = vector<int>;

struct DSU {
    vi parent;
    vi size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // returns the leader of the set with element v
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }


    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
    int get_size(int a) {
        return size[find_set(a)];
    }


};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    set<int> s;
    DSU dsu(n);

    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        if (str == "Union") {
            int a, b;
            cin >> a >> b;
            dsu.union_sets(a - 1, b - 1);
        } else {
            int a;
            cin >> a;
            cout << dsu.get_size(a - 1) << "\n";

        }
    }


}