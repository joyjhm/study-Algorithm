/*
- 다른 사람 풀이
queue를 2개 사용하지 않고 tomaoes에 1 대신 날짜를 사용 
-> 이렇게 하면 메모리 사용 공간 줄어든다.
-> 또 매번 마다 check를 안해줘도 되고 마지막에만 체크를 하면 돼서 시간도 줄어든다.
-> 큐를 번걸아 쓰는 코드 만들지 않아도 돼서 보다 코드가 간단해질 수 있다.

2178번 미로 찾기 문제처럼 bfs를 사용할 때 가중치를 적용하는 생각을 해보자.
*/ 

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
