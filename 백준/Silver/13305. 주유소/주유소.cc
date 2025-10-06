#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<long long> distance(n - 1);
    vector<pair<long long,int>> cost(n);

    for (int i = 0; i < n - 1; i++) {
        cin >> distance[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> cost[i].first;
        cost[i].second = i;
    }

    sort(cost.begin(), cost.end(), [](auto p1, auto p2) {
        return p1.first < p2.first;
    });

    long long result = 0;
    int cnt = n - 1;
    for (int i = 0; i < n; i++) {
        if(cnt == 0) {
            break;
        }
        int idx = cost[i].second;
        int val = cost[i].first;
        for (int j = idx; j < cnt; j++) {
            result += distance[j] * val;
        }
        cnt = min(cnt, idx);
    }

    cout << result;
}