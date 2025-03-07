#pragma GCC optimize("O3,unroll-loops")
#include <cmath>
#include <vector>
#include <iostream>
#include <deque>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    int k, l1, l2;
    cin >> n >> k >> l1 >> l2;
    set<int> s1, s2;
    map<int, int> map1, map2;
    for (int i = 0; i < l1; i++) {
        int temp;
        cin >> temp;
        s1.insert(temp);
        map1[temp] += 1;
    }
    for (int i = 0; i < l2; i++) {
        int temp;
        cin >> temp;
        s2.insert(temp);
        map2[temp] += 1;
    }
    bool finished = false;
    int score = 0;
    for (int i = 200; i > 0; i--) {
        for (auto it = s1.rbegin(); it != s1.rend(); ++it) {
            int x = *it;
            int y = i - x;
            if (y > 100 || x > 100) {
                break;
            }
            if (s2.find(y) != s2.end()) {
                // add the amount in map
                int amount = max(map2[y], map1[x]) * min(map2[y], map1[x]);
                if (amount >= k) {
                    score += k * i;
                    finished = true;
                    break;
                }
                score += amount * i;
                k -= amount;
            }
        }
        if (finished) {
            break;
        }
    }
    cout << score << endl;
}