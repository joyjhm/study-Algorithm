#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> result;
vector<string> v;
bool visited[10001];

bool compare(vector<string> v, vector<string> result) {
    
    if(result.empty())
        return true;
    
    for (int i = 0; i < v.size(); i++) {
        if(v[i] < result[i]) {
            return true;
        } else if(v[i] > result[i]) {
            return false;
        }
    }
    
    return false;
}


void dfs(int idx, int cnt, vector<vector<string>> tickets) {
    
    if(cnt == tickets.size() + 1) {
        if(compare(v, result)) {
            result = v;
        }    
    
        return;
    }
    
    
    for (int i = 0; i < tickets.size(); i++) {
        if(!visited[i] && (tickets[idx][1] == tickets[i][0])) {
            visited[i] = true;
            v.push_back(tickets[i][1]);
            dfs(i, cnt + 1, tickets);
            v.pop_back();
            visited[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    
    for (int i = 0; i < tickets.size(); i++) {
        if(tickets[i][0] == "ICN") {
            v.push_back(tickets[i][0]);
            v.push_back(tickets[i][1]);
            visited[i] = true;
            dfs(i, 2, tickets);
            visited[i] = false;
            v.pop_back();
            v.pop_back();
        }
    
    }
    

    answer = result;
    
    return answer;
}