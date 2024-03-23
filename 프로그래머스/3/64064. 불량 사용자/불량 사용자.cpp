#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int ban_size, user_size;
bool visited[8];
set<set<int>> result;
void dfs(int depth, int idx, vector<string> user_id, vector<string> banned_id) {
    
    
    if(ban_size == depth) {
        set<int> s;
        
        for (int i = 0; i < user_size; i++) {
            if(visited[i]) {
                s.insert(i);
            }
        }
        result.insert(s);
        return;
    }
    
    for (int j = 0; j < user_size; j++) {
        if(banned_id[idx].length() != user_id[j].length()) {
            continue;
        }
        bool breaker = false;
        for(int k = 0; k < banned_id[idx].length(); k++) {

            if(!(user_id[j][k] == banned_id[idx][k] || banned_id[idx][k] == '*')) {
                breaker = true;
                break;
            }                
        }
        if(!breaker && !visited[j]) {
            visited[j] = true;
            dfs(depth + 1, idx + 1, user_id, banned_id);
            visited[j] = false;
        }

    }
    
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    user_size = user_id.size();
    ban_size = banned_id.size();
    
    dfs(0,0, user_id, banned_id);
    answer = result.size();
    
    return answer;
}