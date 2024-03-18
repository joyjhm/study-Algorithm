#include <string>
#include <vector>
#include <iostream>
using namespace std;

int info_size;
bool visited[17];
int val = 0;
vector<int> v[17];

void dfs(int n, vector<int> info, int sheep, int wolf) {
    
    
    if(info[n] == 0) {
        sheep++;
    } else {
        wolf++;
    }
    
    if(sheep > val) {
        val = sheep;
    }
    if (sheep <= wolf) {
        return;
    }

    for (int i = 0; i < info_size; i++) {
        
        if(visited[i]) {
            for (int j = 0; j < v[i].size(); j++) {
                int next = v[i][j];
                if(!visited[next]) {
                    visited[next] = true;
                    dfs(next, info, sheep, wolf);
                    visited[next] = false;
                }
            }
        }
    }    
}


int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    info_size = info.size();
    
    for (int j = 0; j < edges.size(); j++) {
        int start = edges[j][0];
        int dest = edges[j][1];
        v[start].push_back(dest);
        v[dest].push_back(start);

    }
    

    visited[0] = true;
    
    dfs(0, info, 0, 0);
    
    answer = val;
    
    
    return answer;
}