#include<iostream>
#include<queue>
#include<memory.h>

using namespace std;

int n;
char rgb[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[100][100];
char c;
queue<pair<int, int>> q;

void bfs(int i, int j) {
    q.push(make_pair(i, j));
    visited[i][j] = true;
    c = rgb[i][j];
    while(!q.empty()){
        pair<int, int> p = q.front();
        int b = p.first;
        int a = p.second;
        q.pop();

        for(int k = 0; k < 4; k++) {
            int x = a + dx[k];
            int y = b + dy[k]; 
            if(x < 0 || x >= n || y < 0 || y >= n) {
                continue;
            }
            if(c == rgb[y][x] && !visited[y][x]) {
                q.push(make_pair(y,x));
                visited[y][x] = true;
            }  
        }
    }

}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> rgb[i][j];
        }
    }
    int normal, abnormal;
    normal = abnormal = 0;

    // 정상일 때 구역 확인
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                bfs(i, j);
                normal++;
            }
        }
    }

    memset(visited, false, sizeof(visited));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (rgb[i][j] == 'R') {
                rgb[i][j] = 'G';
            }
        }
    }

    // 적록색약일 때 구역 확인
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                bfs(i, j);
                abnormal++;
            }
        }
    }

    cout << normal << " " << abnormal;
}


