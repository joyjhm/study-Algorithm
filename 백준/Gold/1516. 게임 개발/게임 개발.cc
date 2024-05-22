#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> building[501];
vector<int> times(501);
vector<int> result(501, 0);
vector<int> cnt(501);

void topology_sort(int idx) {

    queue<pair<int,int>> q;
    q.push({idx, times[idx]});
    result[idx] = times[idx];
    while(!q.empty()) {
        int cur = q.front().first;
        int t = q.front().second;
        q.pop();

        cnt[cur] = -1;

        for (int i = 0; i < building[cur].size(); i++) {
            int next = building[cur][i];
            result[next] = max(result[next], t + times[next]);
            if (--cnt[next] == 0) {
                q.push({next, result[next]});
            }
        }
    }
    
}


int main() {

    int n;
    cin >> n;


    for (int i = 1; i <= n; i++) {
        cin >> times[i];
        int tmp = 0;
        cin >> tmp;
        while(tmp != -1) {
            building[tmp].push_back(i);
            cin >> tmp;
            cnt[i]++;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) {
            topology_sort(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << result[i] << '\n';
    
    }


}