#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int n, m;
map<string,int> h;
int answer = INT_MAX;

int check(int p, int rock) {
    if(p == 0) {
        return 1;
    }
    else if(p == 1) {
        if(rock == 0) {
            return 5;
        }
        return 1;
    }
    else {
        if(rock == 0) {
            return 25;
        }
        else if(rock == 1) {
            return 5;
        }
        return 1;
    }
}

void dfs(int idx, int used, int used_cnt, int p, int sum, vector<int>& picks, vector<string>& minerals) {
    
    // cout << idx << " " << used << " " << used_cnt << " " << p << " " << sum << '\n';
    
    if (idx >= n || (used >= m + 1)) {
        answer = min(answer, sum);
        return;
    }
    
    int rock = h[minerals[idx]];
    

    
    if(used_cnt == 0 || used_cnt == 5) {
        for (int i = 0; i < 3; i++) {
            if(picks[i] != 0) {
                picks[i]--;
                dfs(idx + 1, used + 1, 1, i, sum + check(i, rock), picks, minerals);
                picks[i]++;                
            }
        }
        
        if(used == m) {
            dfs(idx, used + 1, 1, -1, sum, picks, minerals);
        }
    }
    else {
        dfs(idx + 1, used, used_cnt + 1, p, sum + check(p, rock), picks, minerals);
    }
    
    
}


int solution(vector<int> picks, vector<string> minerals) {
    n = minerals.size();
    m = picks[0] + picks[1] + picks[2];
    h["dia"] = 0;
    h["iron"] = 1;
    h["stone"] = 2;
    int i;
    for (i = 0; i < 3; i++) {
        if(picks[i] != 0) {
            break;
        }
    }
    
 
    dfs(0, 0, 0, 0, 0, picks, minerals);    
    
    

    return answer;
}