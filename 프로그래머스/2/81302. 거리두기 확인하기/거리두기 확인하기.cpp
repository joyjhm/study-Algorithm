#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Len {
    int y;
    int x;
    int dist;
};

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

bool bfs(int t, int y, int x, vector<vector<string>>& places) {
    
    queue<Len> q;
    vector<vector<bool>> visited(5, vector<bool>(5));
    visited[y][x] = true;
    q.push({y, x, 0});
    while(!q.empty()) {
        auto [yy, xx, dist] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ty = yy + dy[i];
            int tx = xx + dx[i];

            if (ty >= 5 || ty < 0 || tx >= 5 || tx < 0) 
                continue;
            
            if(places[t][ty][tx] == 'X' || visited[ty][tx])
                continue;
            
            if(places[t][ty][tx] == 'P')
                return false;

            if(places[t][ty][tx] == 'O' && dist < 1) {
                visited[ty][tx] = true;
                q.push({ty, tx, dist + 1});
            }
        }
    }

    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    int t = places.size();

    for (int i = 0; i < t; i++) {
        int j = 0;
        int k = 0;
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                if(places[i][j][k] == 'P') {
                    if(!bfs(i, j, k, places)) {
                        answer.push_back(0);
                        break;
                    }
                }               
            }

            if(k != 5) {
                break;
            }
        }

        if(j == 5 && k == 5) {
            answer.push_back(1);
        }
    }

    return answer;
}