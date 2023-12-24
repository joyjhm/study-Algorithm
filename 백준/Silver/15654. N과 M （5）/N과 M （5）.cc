#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
int num[8];
bool visited[8];
vector<int> v;

void dfs(int depth) {

    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++) {
        if(visited[i])
            continue;
        visited[i] = true;
        v.push_back(num[i]);
        dfs(depth + 1);
        v.pop_back();
        visited[i] = false;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    dfs(0);

}