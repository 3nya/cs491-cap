#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <iostream>
#include <deque>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vi = vector<int>;

struct node {
    ll parent, left, right;

    void insert(ll parent, ll left, ll right) {

    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> set;
    // node, parent
    map<int, int> map;
    for (int i = 0; i < n; i++) {
        string s;
        int k;
        cin >> s >> k;

        if (s == "Insert") {
            s.push_back(k);

        } else if (s == "Delete") {

        } else if (s == "Kth") {

        } else if (s == "Rank") {

        }
    }
}