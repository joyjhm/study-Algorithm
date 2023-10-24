/*
서로 다른 위치에서 한 번에 같이 시작해야 하는데 따로 시작해서 계속 오류가 났다.
*/
#include<iostream>
#include<queue>
using namespace std;

int tomatoes[100][100][100];
int dz[6] = {0,0,0,0,1,-1};
int dy[6] = {0,1,0,-1,0,0};
int dx[6] = {1,0,-1,0,0,0};
int m, n, h;
int days = 0;
bool unable;

struct Point{
    int z;
    int y;
    int x;

    Point(int z, int y, int x) {
        this->z = z;
        this->y = y;
        this->x = x;
    }

};

queue<Point> q;

void bfs() {
    while(!q.empty()){
        int temp_z = q.front().z;
        int temp_y = q.front().y;
        int temp_x = q.front().x;
        q.pop();
        for(int s = 0; s < 6; s++) {
            int x = temp_x + dx[s];
            int y = temp_y + dy[s];
            int z = temp_z + dz[s];
            if(x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= h)
                continue;
            if(tomatoes[z][y][x] == 0) {
                tomatoes[z][y][x] = tomatoes[temp_z][temp_y][temp_x] + 1;
                q.push(Point(z,y,x));
            }
        }
    }
}

int main() {

    cin >> m >> n >> h;
    for(int k = 0; k < h; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> tomatoes[k][i][j];
                if (tomatoes[k][i][j] == 1) {
                    q.push(Point(k,i,j));
                }
            }
        }
    }

    bfs();


    for(int k = 0; k < h; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(tomatoes[k][i][j] > days) {
                    days = tomatoes[k][i][j];
                }
                if(tomatoes[k][i][j] == 0){
                    unable = true;
                }
            }
        }
    }
    if(unable) {
        cout << -1;
    }
    else {
        cout << days - 1;
    }

}
