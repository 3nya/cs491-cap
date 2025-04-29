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

class KMP {
public:
    KMP(string pat) {
        pat_ = pat;
        int m = pat.length();

        dp_.resize(m, 0);
        int len = 0;  // Length of previous longest prefix suffix
        
        // failure_[0] is always 0
        for (int i = 1; i < m; i++) {
            // Try to extend the previous lps
            while (len > 0 && pat_[i] != pat_[len])
                len = dp_[len-1];
            
            // If characters match, increment length
            if (pat_[i] == pat_[len])
                len++;
                
            dp_[i] = len;
        }
    }
    string search(string txt) {
        int m = pat_.length();
        int n = txt.length();
        int j = 0;
        string ans = "";
        vi prev; 

        for (char c : txt) {
            ans += c;
            while (j > 0 && c != pat_[j]) {
                j = dp_[j-1];
            }
            if (c == pat_[j]) {
                j++;
            }
            prev.push_back(j);
            if (j == m) {
                for (int k = 0; k < m; k++) {
                    ans.pop_back();
                    prev.pop_back();
                }

                if (prev.empty()) {
                    j = 0;
                } else {
                    j = prev.back();

                }
            }

        }
        
        // for (int i = 0; i < n; i++) {
        //     while (j > 0 && txt[i] != pat_[j]) {
        //         j = dp_[j-1];
        //     }
        //     if (txt[i] == pat_[j]) {
        //         j++;
        //     }
        
        //     if (j == m) {
        //         // ans++;
        //         txt = txt.erase(i - m + 1, j);
        //         // cout << txt << endl;
        //         i -= m;
        //         n -= m;
        //         j = dp_[j - 1];
        //     }
        // }
        return ans;
    }
    int getDP(int i) {
        return dp_[i];
    }

private:
    vi dp_;
    string pat_;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    KMP kmp = KMP(t);

    cout << kmp.search(s) << "\n";
}