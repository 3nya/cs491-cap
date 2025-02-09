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
using pi = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> s;
    // key, amount of children
    map<int, int> amount_of_children;

    // key, Left and Right children
    map<int, pair<int, int>> children;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        s.insert(temp);
        children[temp] = {-1, -1};
        amount_of_children.insert({temp, 0});
        auto right = s.upper_bound(temp);
        auto left = (s.lower_bound(temp) == s.begin()) ? s.end() : prev(s.lower_bound(temp));

        if (s.size() == 1) {
            // root case
        } else if (right == s.end()) {
            amount_of_children[*left]++;
            children[*left] = {children[*left].first, temp};
            cout << *left << " ";
        } else if (left == s.end()) {
            amount_of_children[*right]++;
            children[*right] = {temp, children[*right].second};
            cout << *right << " ";
        } else {
            // if (amount_of_children[*left] != 0 && amount_of_children[*right] == 0) { // if left has children and right has no children
            //     cout << *right << "\n";
            //     amount_of_children[*right]++;
            //     children[*right] = {children[*right].first, temp};
            // } else if (amount_of_children[*left] == 0 && amount_of_children[*right] != 0) { // if left has no children and right has children
            //     cout << *left << "\n";
            //     amount_of_children[*left]++;
            //     children[*left] = {temp, children[*right].second};
            // } else {
                // check The left child of the predecessor (A), and the right child of the successor (B).

            pair leftpair = children[*left];
            pair rightpair = children[*right];

            if (leftpair.second == -1) {
                cout << *left << " ";
                amount_of_children[*left]++;
                children[*left] = {leftpair.first, temp};
            } else {
                cout << *right << " ";
                amount_of_children[*right]++;
                children[*right] = {temp, children[*right].second};
            }


            // }
        }
    }
}