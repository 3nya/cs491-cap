#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// hello to whoevers reading this
// i used chatgpt and it did this for me 
// because this question was really too hard
// the robin karp code is from cp-algorithms

const int P = 31;
const int M = 1e9 + 9;
const int N = 5005;

ll p_pow[N];   
ll inv_p[N];   
ll h[N];       

ll modpow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b % 2) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

void prepare_hash(const string& s) {
    int n = s.size();
    p_pow[0] = 1;
    for (int i = 1; i < N; i++)
        p_pow[i] = (p_pow[i - 1] * P) % M;

    inv_p[0] = 1;
    ll inv = modpow(P, M - 2, M); 
    for (int i = 1; i < N; i++)
        inv_p[i] = (inv_p[i - 1] * inv) % M;

    h[0] = 0;
    for (int i = 0; i < n; i++)
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % M;
}

ll get_hash(int l, int r) {
    ll raw = (h[r + 1] - h[l] + M) % M;
    return (raw * inv_p[l]) % M;  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    prepare_hash(s);

    ll total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int max_l = n - j;
            int lcp = 0;
            int lo = 0, hi = max_l;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (get_hash(i, i + mid) == get_hash(j, j + mid)) {
                    lcp = mid + 1;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            total += lcp;
        }
    }

    cout << total << "\n";
}
