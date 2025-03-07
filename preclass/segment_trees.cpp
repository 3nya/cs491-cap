#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <cmath>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
using vl = vector<ll>;

struct node {
    ll max;
};

int getMid(int l, int r) {
    return l + (r - l) / 2;
}

// ss - starting index of segment tree
// se - ending index of segment tree
// qs - starting index of query
// qe - ending index of query
struct node MaxUntill(struct node* st, int ss, int se, int qs, int qe, int index) {
    struct node temp, left, right;
    // if segment is in range, return the node
    if (qs <= ss && qe >= se) {
        return st[index];
    }
    // if outside range (return nothing) 
    if (se < qs || ss > qe) {
        temp.max = -1;
        return temp;
    }
    // if part of the segment is in range
    int mid = getMid(ss, se);
    left = MaxUntill(st, ss, mid, qs, qe, 2 * index + 1);
    right = MaxUntill(st, mid + 1, se, qs, qe, 2 * index + 2);

    temp.max = max(left.max, right.max);
    return temp;
}

// si - index of current node in segment tree
void constructSTUtil(ll arr[], int ss, int se, struct node* st, int si) {
    if (ss == se) {
        st[si].max = arr[ss];
        return; 
    }
    int mid = getMid(ss, se);
    constructSTUtil(arr, ss, mid, st, si * 2 + 1);
    constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);
    st[si].max = max(st[si * 2 + 1].max, st[si * 2 + 2].max);
}

struct node* constructST(ll arr[], int n) {
    int height = (int)(ceil(log2(n)));
    int maxSize = 2 * (int)pow(2, height) - 1;
    struct node* st = new struct node[maxSize];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}

void update(struct node* st, int ss, int se, int index, ll newVal, int si) {
    if (ss == se) {
        st[si].max = newVal;
        return;
    }
    int mid = getMid(ss, se);
    if (index <= mid) {
        update(st, ss, mid, index, newVal, 2 * si + 1);
    } else {
        update(st, mid + 1, se, index, newVal, 2 * si + 2);
    }
    st[si].max = max(st[2 * si + 1].max, st[2 * si + 2].max);
}
const int max_n = 500000;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; 
    cin >> n >> k;

    ll* arr = new ll[n]();
    fill_n(arr, n, 0);

    struct node* segmentTree = constructST(arr, n);

    while (k--) {
        string str;
        ll l, r;
        cin >> str >> l >> r;
        l--;
        if (str == "Add") {
            arr[l] += r;
            update(segmentTree, 0, n - 1, l, arr[l], 0);
        } else if (str == "Max") {
            // for (int i = 0; i < n; i++) {
            //     cout << arr[i] << " ";
            // }
            // cout << endl;
            cout << MaxUntill(segmentTree, 0, n - 1, l, r - 1, 0).max << "\n";
        } else if (str == "Set") {
            arr[l] = r;
            update(segmentTree, 0, n - 1, l, arr[l], 0);
        }
    }



}