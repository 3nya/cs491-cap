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
bool circleIntersect(int x1, int y1, int r1, int x2, int y2, int r2) {
    if (pow(r1 - r2, 2) <= pow(x1 - x2, 2) + pow(y1 - y2, 2) 
        && pow(x1 - x2, 2) + pow(y1 - y2, 2) <= pow(r1 + r2, 2)) {
            return true;
        }
    
    return false;
}

int lineIntersect(int x, int r) {
    if (x - r <= 0 && x + r >= 200) {
        return 3;
    }
    if (x - r <= 0) {
        return 0;
    } 
    if (x + r >= 200) {
        return 1;
    }
    return 2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    DSU dsu(n + 3);
    vvi prev_circles; 
    int line1 = n + 1, line2 = n + 2; // left line, right line
    bool found = false;

    for (int i = 0; i < n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        if (found) {
            continue;
        }

        // check if intersect 
        // cout << "i : " << i << " checking line" << endl;
        if (lineIntersect(x, r) == 3) {
            found = true;
            cout << i << "\n";
            break;
        } else if (lineIntersect(x, r) == 1) {
            dsu.union_sets(i, line2);
        } else if (lineIntersect(x, r) == 0) {
            dsu.union_sets(i, line1);
        }

        // cout << "i : " << i << " checking circles" << endl;
        int index = 0;
        for (vi circle : prev_circles) {
            if (circleIntersect(x,y,r, circle[0], circle[1], circle[2])) {
                dsu.union_sets(i, index);
            }
            index++;
        }
        // cout << "i : " << i << " find set" << endl;

        if (dsu.find_set(line1) == dsu.find_set(line2)) {
            cout << i << "\n";
            found = true;
        }
        // cout << "i : " << i << " finished finding" << endl;

        prev_circles.push_back({x,y,r});
    }
    if (!found) {
        cout << n << "\n";
    }
}