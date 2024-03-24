#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[200];

void bfs(int i, vector<vector<int>> computers) {
    queue<int> q;
    q.push(i);
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int i = 0; i < computers.size(); i++) {
            int con = computers[node][i];
            
            if(!visited[i] && con == 1) {
                visited[i] = true;
                q.push(i);
            }
        }
        
    }
    
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            bfs(i, computers);
            answer++;
        }
    }
    
    
    return answer;
}