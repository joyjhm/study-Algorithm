#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#define limit 1000000

using namespace std;

int solution(int x, int y, int n) {
    int answer = -1;
    
    queue<pair<int,int>> q;
    q.push({x, 0});
    vector<bool> visited(limit + 1, false);
    
    while(!q.empty()) {
        
        int val = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(val > y) {
            continue;
        }
        
        if(val == y) {
            answer = cnt;    
            break;
        }
        
        if(val + n <= limit && !visited[val + n]) {
            visited[val + n] = true;
            q.push({val + n, cnt + 1});
        }
        
        if(val * 2 <= limit && !visited[val * 2]) {
            visited[val * 2] = true;
            q.push({val * 2, cnt + 1});
        }
        
        if(val * 3 < limit && !visited[val * 3]) {
            visited[val * 3] = true;
            q.push({val * 3, cnt + 1});
        } 
    }
    
    
    return answer;
}