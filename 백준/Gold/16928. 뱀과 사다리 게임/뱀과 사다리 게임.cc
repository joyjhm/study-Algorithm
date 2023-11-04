#include<iostream>

using namespace std;

int n, m;
int up[101];
int down[101];
int visited[101];
int result = 1000;
void dfs(int p, int cnt) {

    if(p >= 94) {
        if(result > cnt + 1) {
            result = cnt + 1;
            return;
        }
    }
    else {
        for(int i = 1; i <= 6; i++) {
            if(up[p + i] && (visited[p + i] == 0 || visited[p + i] > cnt + 1)) {
                visited[p + i] = cnt + 1;
                dfs(up[p + i], cnt + 1);
            }
            else if(down[p + i] && (visited[p + i] == 0 || visited[p + i] > cnt + 1)){
                visited[p + i] = cnt + 1;
                dfs(down[p + i], cnt + 1);
            }
            else if((visited[p + i] == 0 || visited[p + i] > cnt + 1) && !up[p + i] && !down[p + i]) {
                visited[p + i] = cnt + 1;
                dfs(p + i, cnt + 1);
            }
        }
    }
}

int main() {

    cin >> n >> m;
    int a,b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        up[a] = b;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        down[a] = b;
    }
    dfs(1, 0);

    cout << result;
}