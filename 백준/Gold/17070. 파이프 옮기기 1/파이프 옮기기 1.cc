#include<iostream>
#include<queue>

using namespace std;

struct Pipe {

    pair<int, int> point;   // 끝 쪽 파이프 위치
    int status; // 0은 가로, 1은 세로, 2는 대각선

    Pipe(pair<int,int> p, int s) {
        point = p;
        status = s;
    }
};

int n;
int house[17][17];
queue<Pipe> q;
int result = 0;

void isWeight(int y, int x) {

    if(x + 1 <= n && house[y][x + 1] != 1) {
        q.push(Pipe({y, x + 1}, 0));
    }

}

void isHeight(int y, int x) {
    if(y + 1 <= n && house[y + 1][x] != 1) {
        q.push(Pipe({y + 1, x}, 1));
    }
}

void isCross(int y, int x) {

    if(y + 1 > n || x + 1 > n)
        return;
    if(!house[y + 1][x] && !house[y][x + 1] && !house[y + 1][x + 1]) {
        q.push(Pipe({y + 1, x + 1}, 2));
    }
}



void bfs() {

    while(!q.empty()) {
        int y = q.front().point.first;
        int x = q.front().point.second;
        int status = q.front().status;
        q.pop();

        if(y == n && x == n) {
            result++;
            continue;
        }
        if(status == 0) {
            isWeight(y, x);
            isCross(y, x);

        }
        else if (status == 1) {
            isHeight(y, x);
            isCross(y, x);
        }
        else {
            isWeight(y, x);
            isCross(y, x);
            isHeight(y, x);
        }
    }


}

int main() {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> house[i][j];
        }
    }

    q.push(Pipe({1,2}, 0));
    bfs();
    cout << result;
}