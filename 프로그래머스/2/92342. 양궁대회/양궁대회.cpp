#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> lions(11);
int score = -1;
int low_score = 0;
int low_cnt = 0;
vector<int> answer(11);

int getScore(vector<int>& info, int n, int cnt) {
    
    int apeach = 0;
    int lion = 0;
    int low = 0;
    for (int i = 0; i < info.size(); i++) {
        if(lions[i] <= info[i]) {
            if(info[i] > 0) {
                apeach += 10 - i;    
            }
        }   
        else {
            lion += 10 - i;
            low = i;
        }
    }

    if(cnt != n) {
        low = 10;
    }

    if(lion > apeach && score <= lion - apeach) {
        if(score == lion - apeach && low < low_score) return -1;
        
        if(score == lion - apeach && low == low_score && lions[low] < low_cnt) return -1;
        
        score = lion - apeach;
        low_score = low;
        low_cnt = lions[low];
        return score;
    }
    return -1;
}


void dfs(int n, vector<int>& info, int cnt, int idx) {
    
    if(idx == info.size() - 1) { 
        lions[10] = 0;          
        if(getScore(info, n, cnt) != -1) {
            // for (int i = 0; i < lions.size(); i++) {
            //     cout << lions[i] << " ";
            // }
            // cout << '\n';

            for (int i = 0; i < info.size() - 1; i++) {
                answer[i] = lions[i];
            }

            answer[info.size() - 1] = n - cnt;

        }
        return;
    }
    
    dfs(n, info, cnt, idx + 1);
    
    int target = info[idx] + 1;
    if(target + cnt <= n) {
        lions[idx] += target;
        dfs(n, info, cnt + target, idx + 1);
        lions[idx] -= target;        
    }
}

vector<int> solution(int n, vector<int> info) {

    dfs(n, info, 0, 0);

    if(score == -1) {
        return {-1};
    }

    return answer;
}