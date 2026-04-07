#include <string>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int n,m;

void bfs(vector<string>& storage, vector<vector<bool>>& visited, int y, int x, char target, vector<pair<int,int>>& removed) {
    
    queue<pair<int, int>> q;
    
    q.push({y, x});
    visited[y][x] = true;
    
    while(!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        char cur = storage[yy][xx];
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int ty = yy + dy[i];
            int tx = xx + dx[i];
            
            if(ty >= n || tx >= m || ty < 0 || tx < 0)
                continue;

            if(!visited[ty][tx] && (storage[ty][tx] == target)) {
                removed.push_back({ty, tx});
                visited[ty][tx] = true;
            }
            if(!visited[ty][tx] && storage[ty][tx] == '0') {
                visited[ty][tx] = true;
                q.push({ty,tx});
            }
        }
    }
}


int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    n = storage.size();
    m = storage[0].size();
    char blank = '0';
    for (int k = 0; k < requests.size(); k++) {
        int target = requests[k][0];
        if(requests[k].length() > 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if(storage[i][j] == target) {
                        storage[i][j] = blank;
                    }
                }
            }            
        }
        else {
            vector<vector<bool>> visited(n, vector<bool>(m));
            vector<pair<int,int>> removed;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if((i == 0 || j == 0 || i == n - 1 || j == m - 1)) {
                        if(storage[i][j] == target) {
                            removed.push_back({i, j});
                        }
                        else if(!visited[i][j] && storage[i][j] == '0') {
                            bfs(storage, visited, i, j, target, removed);                                
                        }

                    } 
                }
            }

            for (int i = 0; i < removed.size(); i++) {
                storage[removed[i].first][removed[i].second] = '0';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(storage[i][j] != '0') {
                answer++;
            }
        }
    }


    return answer;
}