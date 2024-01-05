#include<iostream>
#include<vector>

using namespace std;

int n, m;
bool visited[9];
vector<int> v;
void dfs(int depth, int idx) {

    if(depth == m) {
        for(int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = idx; i <= n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            v.push_back(i);
            dfs(depth + 1, i + 1);
            v.pop_back();
            visited[i] = false;
        }
    }

}

int main() {

    cin >> n >> m;
    dfs(0, 1);
}