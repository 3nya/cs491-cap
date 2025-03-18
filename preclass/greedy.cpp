#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    long long c;
    cin >> n >> c;

    vector<int> v(n);
    // priority_queue<long long> pq;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        pq.push(temp);
    }
    long long total = 0;
    while (pq.size() >= 2) {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();

        pq.push(first + second);
        total += first + second + c;
    }
    cout << total << "\n";



    
}