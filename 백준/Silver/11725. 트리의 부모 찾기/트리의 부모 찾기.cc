#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n;
vector<int> node[100001];
bool visited[100001];
int result[100001];
queue<int> q;
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    q.push(1);

    while(!q.empty()){
        int target = q.front();
        q.pop();
        for(int i = 0; i < node[target].size(); i++){
            int idx = node[target][i];
            if(!visited[idx]) {
                visited[idx] = true;
                result[idx] = target;
                q.push(idx);
            }
        }
    }

    for (int i = 2; i <=n; i++) {
        cout << result[i] << '\n';
    }
}


