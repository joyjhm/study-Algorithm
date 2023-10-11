#include<iostream>
#include<queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q[2]; 
int tomatoes[1002][1002];
int m,n;

bool check() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(tomatoes[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void bfs(int queueNumber) {
    int useQueue, emptyQueue;
    if (queueNumber % 2 == 0) {
        useQueue = 0;
        emptyQueue = 1;
    }
    else {
        useQueue = 1;
        emptyQueue = 0;
    }
    while(!q[useQueue].empty()) {
        pair<int, int> p = q[useQueue].front();
        int a = p.first;
        int b = p.second;
        q[useQueue].pop();
        for (int i = 0; i < 4; i++) {
            int x = dx[i] + b;
            int y = dy[i] + a;
            if(x > 0 && y > 0 && x <= m && y <= n && tomatoes[y][x] == 0) {
                tomatoes[y][x] = 1;
                q[emptyQueue].push(make_pair(y, x));
                
            }
        }
    }
}

int main() {
    cin >> m >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> tomatoes[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(tomatoes[i][j] == 1) {
                q[0].push(make_pair(i,j));
            }
        }
    }
    int result = 0;
    while(true) {
        if(check()) {
            break;
        }
        else {
            if(q[0].empty() && q[1].empty()) {
                result = -1;
                break;
            }
            bfs(result);
            result++;
        }
    }

    cout << result;
}