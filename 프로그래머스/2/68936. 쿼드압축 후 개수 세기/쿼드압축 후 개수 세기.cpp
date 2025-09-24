#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dx[4] = {0, 1, 0, 1};
int dy[4] = {0, 0, 1, 1};

pair<int,int> recursive(vector<vector<int>>& arr, int n, int x, int y, pair<int,int> val) {
        
    pair<int,int> p = {0, 0};
    
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if(arr[i][j] == 0) {
                p.first++;
            }
            else {
                p.second++;    
            }
            
        }
    }


    
    if(p.first == n * n) {
        return {1, 0};
    }
    if(p.second == n * n) {
        return {0, 1};
    }

    if(n == 2) {
        val.first += p.first;
        val.second += p.second;
        return val;
    }
    
    p = {0, 0};

    for (int i = 0; i < 4; i++) {
        pair<int,int> tmp = recursive(arr, n / 2, x + dx[i] * (n / 2), y + dy[i] * (n / 2), val);
        p.first += tmp.first;
        p.second += tmp.second;
    }

    return p;
}


vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2);
    
    pair<int,int> p = recursive(arr, arr.size(), 0, 0, {0, 0});

    answer[0] = p.first;
    answer[1] = p.second;
    
    return answer;
}