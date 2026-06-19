#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int bfs(int idx, vector<int> graph[], int n) {
    
    vector<bool> visited(n + 1);
    queue<int> q;
    int cnt = 0;
    
    visited[idx] = true;
    q.push(idx);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        cnt++;
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return cnt;
}


int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<int> win[n + 1];
    vector<int> lose[n + 1];

    
    for (int i = 0; i < results.size(); i++) {
        win[results[i][0]].push_back(results[i][1]);
        lose[results[i][1]].push_back(results[i][0]);
    }
    
    for (int i = 1; i <= n; i++) {
        int winCnt = bfs(i, win, n);
        int loseCnt = bfs(i, lose, n);
        // cout << i << "번째: " << winCnt << " " << loseCnt << '\n';
        if(winCnt + loseCnt == n + 1) {
            answer++;
        }
    }
    
    return answer;
}