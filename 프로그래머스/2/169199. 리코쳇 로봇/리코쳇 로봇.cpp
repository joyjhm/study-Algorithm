#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point { 
    int y;
    int x;
    int cnt;
};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int start_x, start_y, target_x, target_y, size_y, size_x;
bool visited[100][100];


int bfs(vector<string> &board) {
    queue<Point> q;
    q.push({start_y, start_x, 0});
    bool visited[100][100] = {false, };
    visited[start_y][start_x] = true;
    
    while(!q.empty()) {
        int ty = q.front().y;
        int tx = q.front().x;
        int cnt = q.front().cnt;
        q.pop();
        
        
        if(ty == target_y && tx == target_x) {
            return cnt;
        }
        
        for (int i = 0; i < 4; i++) {
            int y = ty;
            int x = tx;
            while(true) {
                int bx = x + dx[i];
                int by = y + dy[i];
                
                if(bx < 0 || by < 0 || bx >= size_x || by >= size_y) {
                    break;
                }
                
                if(board[by][bx] == 'D') {
                    break;
                }
                
                y = by;
                x = bx;
                
            }
            
            if (x < 0 || x >= size_x || y < 0 || y >= size_y)
                continue;
            
            if(!visited[y][x]) {
                visited[y][x] = true;
                q.push({y,x, cnt + 1});
                
            }
            
        }  
    }
    
    return -1;
}


int solution(vector<string> board) {
    int answer = 0;
    
    size_y = board.size();
    
    for (int i = 0; i < board.size(); i++) {
        size_x = board[i].size();
        for (int j = 0; j < board[i].length(); j++) {

            if (board[i][j] == 'R') {
                start_y = i;
                start_x = j;
            }
            
            if (board[i][j] == 'G') {
                target_y = i;
                target_x = j;
            }
        }
    }
    
    answer = bfs(board);
    
    return answer;
    
}