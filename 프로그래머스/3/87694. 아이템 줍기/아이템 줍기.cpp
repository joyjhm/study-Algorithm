#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int visited[51][51];
queue<pair<int,int>> q;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
vector<vector<int>> arr;


bool isPossible(float ty, float tx, int yy, int xx, vector<int> v) {
    for (int i = 0; i < arr.size(); i++) {
        if(arr[i][0] < tx && tx < arr[i][2] && arr[i][1] < ty && ty < arr[i][3])
            return false;
    }
    
    
    for (int i = 0; i < v.size(); i++) {
        int target = v[i];
        if(((arr[target][0] == xx || arr[target][2] == xx) 
           && (arr[target][1] <= yy && yy <= arr[target][3])) || 
           ((arr[target][1] == yy || arr[target][3] == yy) && (arr[target][0] <= xx && xx <= arr[target][2]))) 
                return true; 
    }
        
    return false;
}

vector<int> check(int y, int x) {
    
    vector<int> v;
    
    for (int i = 0; i < arr.size(); i++) {
        if(((arr[i][0] == x || arr[i][2] == x) 
           && (arr[i][1] <= y && y <= arr[i][3])) || 
           ((arr[i][1] == y || arr[i][3] == y) && (arr[i][0] <= x && x <= arr[i][2]))) {
            v.push_back(i);
        } 
    }
    
    return v;
}


int bfs(int itemY, int itemX) {
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        vector<int> v = check(y, x);
        q.pop();
                
        
        if(y == itemY && x == itemX) {
            return visited[y][x] - 1;
        }
        
        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            
            float ty = y + dy[i] * 0.5;
            float tx = x + dx[i] * 0.5;
            
            if(yy > 50 || yy <= 0 || xx > 50 || xx <= 0)
                continue;
            
            if(!visited[yy][xx] && isPossible(ty, tx, yy, xx, v)) {
                visited[yy][xx] = visited[y][x] + 1;
                q.push({yy, xx});
            }
        }
    }
    
    return -1;
}


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    arr = rectangle;
    visited[characterY][characterX] = 1;
    
    q.push({characterY, characterX});
    answer = bfs(itemY, itemX);
    return answer;
}