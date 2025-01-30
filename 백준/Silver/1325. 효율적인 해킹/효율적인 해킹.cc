#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
vector<int> computer[10001];
vector<int> v;
int result = 0;
bool visited[10001];
int connect[10001];
int cnt = 1;

void dfs(int idx) {
    visited[idx] = true;

    for (int i = 0; i < computer[idx].size(); i++) {
        int next= computer[idx][i];
        if(!visited[next]) {
            visited[next] = true;
            dfs(next);  
            cnt++;  
        }
    }
}

void reset() {

    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;


    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        computer[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        dfs(i);
        reset();
        result = max(result, cnt);
        connect[i] = cnt;
        cnt = 1;
    }

    for (int i = 1; i <= n; i++) {
        if(connect[i] == result) {
            cout << i << " ";
        }
    }
    
}