#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int main() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n);

    priority_queue<int, vector<int>> pq;
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        pq.push(x[i]);
        sum += x[i];

        if (sum >= m) {
            sum -= pq.top() * 2;
            pq.pop();
            cnt++;
        }
    }

    cout << cnt;



}