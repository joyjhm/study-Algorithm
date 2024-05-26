#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
    int y;
    int x;
    int d;
};

int n, m, d;
int map[15][15];
int copy_map[15][15];
int result;
int enemy;
bool visited[15];
vector<int> archer;
int dy[3] = {0,-1,0};
int dx[3] = {-1,0,1};

void game() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {   // i는 궁수의 행위치

        vector<pair<int,int>> kill;
        bool visited_map[15][15][3] = {false, };

        for (int j = 0; j < 3; j++) {
            queue<Point> q;
            q.push({n - i - 1, archer[j], 1});

            while(!q.empty()) {
                int y = q.front().y;
                int x = q.front().x;
                int distance = q.front().d;
                q.pop();

                if(copy_map[y][x] == 1) {
                    kill.push_back({y,x});
                    break;
                }

                for (int k = 0; k < 3; k++) {
                    int yy = y + dy[k];
                    int xx = x + dx[k];

                    if(yy >= n || x >= m || yy < 0 || xx < 0)
                        continue;

                    if(!visited_map[yy][xx][j] && distance + 1 <= d) {
                        visited_map[yy][xx][j] = true;
                        q.push({yy,xx, distance + 1});
                    }
                    
                }
            }

        }

        for (int i = 0; i < kill.size(); i++) {
            int y = kill[i].first;
            int x = kill[i].second;
            if(copy_map[y][x] == 1) {
                copy_map[y][x] = 0;
                cnt++;
            }
        }

    }

    result = max(result, cnt);
    
}

void arrange_archer(int idx, int cnt) {

    if (result == enemy) {
        return;
    }

    if (cnt == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                copy_map[i][j] = map[i][j];
            }
        }
        game();
        return;
    }

    for (int i = idx; i < m; i++) {
        if(!visited[i]) {
            visited[i] = true;
            archer.push_back(i);
            arrange_archer(idx + 1, cnt + 1);
            archer.pop_back();
            visited[i] = false;
        }
    }

}


int main() {

    cin >> n >> m >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) {
                enemy++;
            }
        }
    }

    arrange_archer(0, 0);

    cout << result;
}