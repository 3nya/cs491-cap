#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <cmath>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
using vl = vector<ll>;

int n;
int block_size;
vl original_arr;
vl block;
map<int, int> block_sizes; // index, size of block
vl intervals; // this will keep the left end of the intervals
ll lowbit(ll x) {
    return x & -x;
}

ll exponent(int l, int i) {
    int ret = 0;
    ll arg = (l + 1) ^ ((i + 1) / block_size);
    ll exp = lowbit(arg);

    if (exp % 2 == 0)
        ret = 1;
    else
        ret = -1;
    return ret;
}
ll query(int l, int r) {
    ll sum = 0;
    int i = 0;
    int lconst = l;

    // first block that can be used
    while (i + 1 < intervals.size() && intervals[i + 1] < l) {
        i++;
    }
    i++;

    // first block (partial sum before a full block starts)
    bool used = false;
    while (l < intervals[i]) {
        // cout << "first adding " << original_arr[l] << " * " << exponent(lconst, l) << endl;
        sum += original_arr[l] * exponent(lconst, l);
        l++;
    }

    // overlapping middle blocks
    while (intervals[i] + block_sizes[i] <= r) {
        // cout << "second adding " << block[i] << " * " << exponent(lconst, l) << endl;
        sum += block[i] * exponent(lconst, l);
        l += block_sizes[i];
        i++;
    }

    // last block
    while (l <= r) {
        // cout << "third adding " << original_arr[l] << " * " << exponent(lconst, l) << endl;
        sum += original_arr[l] * exponent(lconst, l);
        l++;
    }
    return sum;
}
ll brute_force_query(int l, int r) {
    ll ret = 0;
    for (int i = l; i <= r; i++) {
        // we have to add 1 because we subtract 1 from the indices
        // before calling this function
        ll arg = (l + 1) ^ ((i + 1) / block_size);
        ll exp = lowbit(arg);

        if (exp % 2 == 0)
            ret += original_arr[i];
        else
            ret += original_arr[i] * -1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;
    block_size = sqrt(n);
    original_arr.resize(n);
    block.resize(n);
    for (int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        original_arr[i] = temp;
    }


    // making the blocks
    int prev = 0;
    int size = 0;
    int block_index = -1;
    intervals.push_back(0);  
    for (int i = 0; i < n; i++) {  
        block_index = floor((i + 1) / sqrt(n));  
        block[block_index] += original_arr[i];  
    
        if (block_index != prev) {  
            intervals.push_back(i);  
            block_sizes[prev] = size;  
            size = 0;
            prev = block_index;
        }
        size++;
    }
    block_sizes[prev] = size;

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << query(l - 1, r - 1) << endl;
        // cout << brute_force_query(l - 1, r - 1) << endl;
    }
    
}