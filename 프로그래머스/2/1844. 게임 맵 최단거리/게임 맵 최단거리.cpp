#include <vector>
#include <queue>
#include <iostream>

using namespace std;

queue<pair<int,int>> q;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int n, m;
int visited[100][100];

int bfs(vector<vector<int>> maps) {
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        if(y == n - 1 && x == m - 1) {
            return visited[y][x];
        }
        
        
        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            
            if(yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            
            
            if(maps[yy][xx] && !visited[yy][xx]) {
                visited[yy][xx] = visited[y][x] + 1;
                q.push({yy, xx});
            }
        }
    }
    
    
    return -1;
}


int solution(vector<vector<int>> maps)
{
    
    q.push({0,0});
    visited[0][0] = 1;
    
    n = maps.size();
    m = maps[0].size();
        
    int answer = bfs(maps);

    return answer;
}