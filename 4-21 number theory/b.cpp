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

    // first find primes < N
    vector<bool> v(n + 1, true);
    v[0] = false;
    v[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (v[i]) {
            for (ll j = i * i; j <= n; j += i) {
                v[j] = false;
            }
        }
    }

    // for (i = 2 ... sqrt(n))

    set<int> sols; 
    map<int, int> nums; 
    for (int i = 2; i <= n; i++) {
        if (v[i] == 1) { // if v[i] is prime
            int c = 0;
            for (int k = 1; pow(i, k) <= n; k++) {
                c += floor(n / pow(i, k));
            }
            nums[i] = c;
        }
    }

    cout << nums.size() << "\n";
    for (pair<int, int> num : nums) {
        cout << num.first << " " << num.second << "\n";
    }
    // if s[i] == 0, i is a prime
    
    // exit if 
    // for (primes we have <= i)
    //   s[primes * y] == true
    //   if i % prime == 0, break
    // dont count primes

    // sieve through the remaining numbers
    //  

}