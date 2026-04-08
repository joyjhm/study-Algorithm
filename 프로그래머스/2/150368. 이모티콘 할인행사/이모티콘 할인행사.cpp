#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n, m;
vector<int> sales;
int max_count, max_income;

void calculate(vector<vector<int>>& users, vector<int>& emoticons) {
    
    int count = 0;
    int income = 0;
    

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            if(users[i][0] <= sales[j]) {
                sum += ((100 - sales[j])) * emoticons[j] / 100;
            }
        } 
        if(sum >= users[i][1]) {
            count++;
        }
        else {
            income += sum;
        }
    }

    if(max_count < count) {
        max_count = count;
        max_income = income;
    }
    else if (max_count == count) {
        if(income > max_income) {
            max_income = income;
        }
    }
}

void dfs(int idx, vector<vector<int>>& users, vector<int>& emoticons) {
    
    if(idx == m) {
        calculate(users, emoticons);
        return;
    }
    
    for (int i = idx; i < m; i++) {
        for (int j = 10; j <= 40; j += 10) {
            sales.push_back(j);
            dfs(i + 1, users, emoticons);
            sales.pop_back();
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;

    n = users.size();
    m = emoticons.size();

    dfs(0, users, emoticons);

    return {max_count, max_income};
}