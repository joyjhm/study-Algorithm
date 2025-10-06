#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int k;
        cin >> k;
        vector<int> arr(k);
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int i = 0; i < k; i++) {
            int n;
            cin >> n;
            pq.push(n);
        }

        long long sum = 0;
        while(pq.size() != 1) {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            sum += first + second;
            pq.push(first + second);
        }

        cout << sum << '\n';
    }
}