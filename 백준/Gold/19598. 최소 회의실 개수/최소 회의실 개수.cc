#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;


int main() {

    int n;
    cin >> n;
    vector<pair<int,int>> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), [](auto& p1, auto& p2) {
        if(p1.first == p2.first) {
            return p2.second < p1.second;
        }
        return p1.first < p2.first;
    });

    priority_queue<int, vector<int>, greater<int>> pq;
    int result = 0;
    for (int i = 0; i < n; i++) {
        while(!pq.empty() && pq.top() <= v[i].first) {
            pq.pop();
        }
        pq.push(v[i].second);
        result = max(result, (int) pq.size());
    }

    cout << result;
}