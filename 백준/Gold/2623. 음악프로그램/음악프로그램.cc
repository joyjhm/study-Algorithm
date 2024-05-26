#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> singer[1001];
int cnt[1001];
bool visited[1001];
vector<int> result;
void topology_sort() {

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if(cnt[i] == 0) {
            q.push(i);
            result.push_back(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < singer[node].size(); i++) {
            int next = singer[node][i];
            cnt[next]--;
            if(cnt[next] == 0) {
                q.push(next);
                result.push_back(next);
            }
        }
    }
}


int main() {
    
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        int pre = 0;
        for (int j = 0; j < num; j++) {
            int s;
            cin >> s;
            if(pre != 0) {
                singer[pre].push_back(s);
                cnt[s]++;
            }   
            pre = s;
        }
    }

    topology_sort();

    if(result.size() == n) {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << '\n';
        }
    }
    else {
        cout << 0;
    }
}
 