#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;

int space[20][20];
int n;
int idx = 0;
int shark_size = 2;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<pair<int, int>> v[7];
queue<pair<int, int>> ableFish;
int x, y;

bool isEmpty() {
    for (int i = 1; i <= 6; i++) {
        if (shark_size <= i) {
            return true;
        }
        if(!v[i].empty()) {
            return false;
        }
    }
    return true;
}

int bfs(queue<pair<int,int>> q) {
    int temp_space[20][20] = {0};
    bool visited[20][20] = {false};
    visited[q.front().first][q.front().second] = true;
    while(!q.empty()) {
        int shark_y = q.front().first;
        int shark_x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int tx = dx[i] + shark_x;
            int ty = dy[i] + shark_y;

            if(tx < 0 || tx >= n || ty < 0 || ty >= n)
                continue;

            if(space[ty][tx] <= shark_size && !visited[ty][tx]) {
                visited[ty][tx] = true;
                temp_space[ty][tx] = temp_space[shark_y][shark_x] + 1;
                q.push(make_pair(ty,tx));
                if(space[ty][tx] && space[ty][tx] < shark_size) {
                    ableFish.push(make_pair(ty,tx));
                }
            }
        }
    }

    int min_distance = 1000;
    int target = 0;
    int target_size = 0;
    int target_y, target_x;

    while(!ableFish.empty()) {

        int ty = ableFish.front().first;
        int tx = ableFish.front().second;
        int tsize = space[ty][tx];
        int temp = temp_space[ty][tx];

        if (temp <= min_distance) {
                if(temp == min_distance) {
                    if (target_y > ty) {

                        target_y = ty;
                        target_x = tx;
                        target_size = tsize;

                    }
                    else if (target_y == ty) {
                        if (target_x > tx) {

                        target_y = ty;
                        target_x = tx;
                        target_size = tsize;

                        }
                    }
                }
                else if(temp < min_distance) {
                    min_distance = temp;
                    target_y = ty;
                    target_x = tx;
                    target_size = tsize;

                }
            }
            ableFish.pop();
    }
    if (min_distance == 1000) {
        return min_distance;
    }

    y = target_y;
    x = target_x;
    space[y][x] = 0;
    pair<int, int> p = make_pair(target_y, target_x);
    for(int i = 0; i < v[target_size].size(); i++) {
        if (v[target_size][i].first == target_y && v[target_size][i].second == target_x) {
            v[target_size].erase(v[target_size].begin() + i);
        }
    }
    return min_distance;
}

int getDistance(int shark_y, int shark_x) {
    queue<pair<int, int>> q;
    q.push(make_pair(shark_y, shark_x));
    int distance = bfs(q);
    return distance; 
}

int main() {

    cin >> n;
    int num;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> num;
            space[i][j] = num;
            if(num == 9) {
                y = i;
                x = j;
                space[y][x] = 0;
            }
            if(num > 0 && num < 7) {
                v[num].push_back(make_pair(i, j));
            }
        }
    }

    int result = 0;
    
    while (!isEmpty()) {
        int addDistance = getDistance(y, x);
        if (addDistance == 1000) {
            break;
        }
        result += addDistance;
        idx++;
        if(idx == shark_size) {
            idx = 0;
            shark_size++;
        }
    }

    cout << result;
}