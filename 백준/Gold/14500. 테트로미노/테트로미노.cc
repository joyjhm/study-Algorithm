#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int paper[501][501];
int n, m;
bool visited[501][501];
int result = 0;
vector<pair<int, int>> v;

void dfs(int index, int sum) {

    if (index == 4) {
        result = result < sum ? sum : result;
        return;
    }
    for(int i = 0; i < v.size(); i++) {
        int temp_y = v[i].first;
        int temp_x = v[i].second;
        for (int j = 0; j < 4; j++) {
            int nx = temp_x + dx[j];
            int ny = temp_y + dy[j];

            if (nx <= 0 || nx > m || ny <= 0 || ny > n) {
                continue;
            }
            if (!visited[ny][nx]) {
                visited[ny][nx] = true;
                v.push_back(make_pair(ny, nx));
                dfs(index + 1, sum + paper[ny][nx]);
                v.pop_back();
                visited[ny][nx] = false;
            }
    }
    }
   
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> paper[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            visited[i][j] = true;
            v.push_back(make_pair(i, j));
            dfs(1, paper[i][j]);
            v.pop_back();
        }
    }

    cout << result;
}