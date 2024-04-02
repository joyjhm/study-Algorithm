#include <iostream>
#include <queue>
#include <deque>
using namespace std;

struct Snake {
    int y;
    int x;
};

int n, k, l;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board[101][101];
bool visited[100];
bool breaker = false;

deque<Snake> deq;
queue<pair<int,char>> change;
vector<pair<int,int>> apple;

int move() {
    int dir = 0;
    int t = 0;
    while(!breaker) {
        int y = deq.front().y;
        int x = deq.front().x;
        int cnt = deq.size();

        int next_y = y + dy[dir];
        int next_x = x + dx[dir];
        t++;

        if(t == change.front().first) {
            char c = change.front().second;
            if (c == 'D') {
                dir++;
            }
            else {
                dir--;
            }
            change.pop();
        }

        if(dir < 0) {
            dir = 3;
        } 
        else if (dir > 3) {
            dir = 0;
        }

        if (next_y > n || next_x > n || next_x <= 0 || next_y <= 0)
            break;

        for (int i = 0; i < deq.size(); i++) {
            if (deq[i].y == next_y && deq[i].x == next_x) {
                breaker = true;
            }
        }


        for (int i = 0; i < apple.size(); i++) {
            if(apple[i].first == next_y && apple[i].second == next_x && !visited[i]) {
                visited[i] = true;
                cnt++;
            }
        }

        deq.push_front({next_y, next_x});

        if (cnt != deq.size()) {
            deq.pop_back();
        } 
    }

    return t;
}


int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        apple.push_back({y,x});
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        int x;
        char c;
        cin >> x >> c;
        change.push({x, c});
    }

    deq.push_front({1, 1});
    int answer = move();

    cout << answer;
}