#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

int row, col;
vector<int> key;
vector<vector<int>> cases;
int answer;

bool compare(vector<int>& a, vector<int> b) {
    return a.size() < b.size();
}

bool check(vector<vector<string>>& relation) {
    
    map<string,int> data;
    for (int i = 0; i < row; i++) {
        string val = "";
        for (int k = 0; k < key.size(); k++) {
            val += relation[i][key[k]];
        } 
        if(data[val] > 0) {
            return false;
        }     
        data[val]++;
    }

    cases.push_back(key);
    return true;
}

void dfs(int idx, vector<vector<string>>& relation) {

    if(idx == col) {
        // for (int i = 0; i < key.size(); i++) {
        //     cout << key[i] << " ";
        // }
        // cout << '\n';
        check(relation);
        return;
    }
        
    key.push_back(idx);
    dfs(idx + 1, relation);
    key.pop_back();
    
    dfs(idx + 1, relation);
}

int solution(vector<vector<string>> relation) {
    row = relation.size();
    col = relation[0].size();
        
    dfs(0, relation);

    vector<long long> result;
    
    // for (int i = 0; i < cases.size(); i++) {
    //     for (int j = 0; j < cases[i].size(); j++) {
    //         cout << cases[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    sort(cases.begin(), cases.end(), compare);

    for (int i = 0; i < cases.size(); i++) {
        long long val = 0; 
        for (int j = 0; j < cases[i].size(); j++) {
            int idx = cases[i][j];   
            val |= (1 << idx);
        }
        int k = 0;
        for (k = 0; k < result.size(); k++) {
            if ((result[k] & val) == result[k] || (result[k] & val) == val) {
                result[k] = min(val, result[k]);
                break;
            }
        }
        if(k == result.size()) {
            result.push_back(val);
        }
    }

    answer = result.size();

    return answer;
}