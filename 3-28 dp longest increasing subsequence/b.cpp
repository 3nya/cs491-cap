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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vi v(n);

    map<int, int> first; 
    map<int, int> last;
    for (int i = 0; i < n; i++) {
        cin >> v[i];

        if (!first.count(v[i])) {
            first[v[i]] = i;
        }
        last[v[i]] = i;
    }
    sort(v.begin(), v.end());
    vector<int>::iterator ip = unique(v.begin(), v.begin() + n);
    v.resize(distance(v.begin(), ip));

    // for (int i : v) {
    //     cout << i << endl;
    // }

    vi pl(k);
    vi pr(k);

    vi ql(k);
    vi qr(k);
    
    // value, index
    map<int, int> indices;
    for (int i = 0; i < k; i++) {
        cin >> pl[i];
        // ql[i] = first(w_pl_i)
        ql[i] = first[v[pl[i] - 1]] + 1;

        indices[ql[i]] = i;
    }
    vi sequence(k);
    for (int i = 0; i < k; i++) {
        cin >> pr[i];
        qr[i] = last[v[pr[i] - 1]] + 1;

        if (!indices.count(qr[i])) {
            sequence[i] = -10000000;
        } else {
            sequence[i] = indices[qr[i]];
        }
    }

    vi ans;
    
    vi indexes(k + 1, -1);   // indexes will keep track of the indexes of elements in our ans vector 
    vi ancestors(k + 1, -1); // ancestors[i] will be the index of previous element for optimal subsequence
                         // ending in element i

    ans.push_back(-1);
    for (int i = 0; i < k; i++) {
        if (sequence[i] > ans.back()) {
            ancestors[i] = indexes[ans.size() - 1]; // keeping track of the last element (could be updated later)
                                                    // of longest subsequence at element i

            // if current number is greater than the last element of answer vector
            // we found the longer inc subsequence
            ans.push_back(sequence[i]);
            indexes[ans.size() - 1] = i; // index of this elemement
            
        } else {
            // if current number is NOT greater than last element
            // binary search to find the smallest element in the answer vector
            // that is greater or equal to the current number
            int low = lower_bound(ans.begin(), ans.end(), sequence[i]) - ans.begin();
            if (sequence[i] < ans[low] && low >= 0) { // v[i] > ans[low - 1] 
                ans[low] = sequence[i];
                indexes[low] = i;
    
                // Im pretty sure this part is wrong but i just dont know how 
                // 
                if (low > 0) {
                    ancestors[i] = indexes[low - 1];
                }
            }
        }
    }

    cout << ans.size() - 1 << "\n";

}