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

    int n;
    cin >> n;

    vi v(n);
    vi ans;
    
    vi indexes(n + 1, -1);   // indexes will keep track of the indexes of elements in our ans vector 
    vi ancestors(n + 1, -1); // ancestors[i] will be the index of previous element for optimal subsequence
                         // ending in element i
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ans.push_back(-1);
    for (int i = 0; i < n; i++) {
        if (v[i] > ans.back()) {
            ancestors[i] = indexes[ans.size() - 1]; // keeping track of the last element (could be updated later)
                                                    // of longest subsequence at element i

            // if current number is greater than the last element of answer vector
            // we found the longer inc subsequence
            ans.push_back(v[i]);
            indexes[ans.size() - 1] = i; // index of this elemement
            
        } else {
            // if current number is NOT greater than last element
            // binary search to find the smallest element in the answer vector
            // that is greater or equal to the current number
            int low = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
            if (v[i] < ans[low] && low >= 0) { // v[i] > ans[low - 1] 
                ans[low] = v[i];
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
    
    // restoring the longest increasing subsequence
    int ind = indexes[ans.size() - 1]; // last index of the longest inc subsequence
    vi temp;
    while (ind != -1) {
        temp.push_back(v[ind]);
        ind = ancestors[ind];
    }
    reverse(temp.begin(), temp.end());

    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i] << " ";
    }
    cout << "\n";

}