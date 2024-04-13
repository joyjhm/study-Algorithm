#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> top(n + 1);   
    vector<int> result(n + 1, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for (int i = 1; i <= n; i++) {
        cin >> top[i];
    }
    pq.push({top[n], n});
    for (int i = n - 1; i > 0; i--) {
        while(!pq.empty() && pq.top().first < top[i]) {
            int val = pq.top().first;
            int idx = pq.top().second;
            if (top[i] > val) {
                result[idx] = i;
                pq.pop();
            }
        }
        pq.push({top[i], i});
    }

    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }

}