#include<iostream>
#include<queue>
using namespace std;

bool ground[51][51];
queue<pair<int, int>> q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int result = 0;

void bfs() {

    while(!q.empty()) {

        pair<int, int> p = q.front();
        int a = p.first;
        int b = p.second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int y = dy[i] + a;
            int x = dx[i] + b;
            if(y >= 0 && x >= 0 &&  ground[y][x]) {
                q.push(make_pair(y, x));
                ground[y][x] = false;
            }
        }
    }
}

int main() {

    int t;
    cin >> t;
    while(t--) {
        int m, n, k;
        cin >> m >> n >> k;
        int x,y;
        for (int i =0; i < k; i++) {
            cin >> x >> y;
            ground[y][x] = true;
        }

        result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(ground[i][j]) {
                    q.push(make_pair(i, j));
                    ground[i][j] = false;
                    bfs();     
                    result++;      
                }
            }
        }
        cout << result << endl;
        
    }
}