#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


map<string, int> course_map[11];

bool compare(pair<string,int> p1, pair<string,int> p2) {
    return p2.second < p1.second;
}

void dfs(string str, int idx , int cnt, string val) {
    
    
    if (cnt == val.length()) {
        course_map[cnt][val]++;
        return;
    }
    
    for (int i = idx; i < str.length(); i++) {
        dfs(str, i + 1, cnt, val + str[i]);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    int n = orders.size();
    int m = course.size();
    
    for (int i = 0; i < n; i++) {
        sort(orders[i].begin(), orders[i].end());
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int len = course[j];
            dfs(orders[i], 0, len, "");
        }
    }
    
    for (int i = 0; i < m; i++) {
        int len = course[i];
        vector<pair<string,int>> v;
        for (auto [str, cnt]: course_map[len]) {
            if(cnt >= 2) {
                v.push_back({str, cnt});
            }
        }   
        sort(v.begin(), v.end(), compare);
        if(!v.empty()) {
            int max_val = v[0].second;
            for (auto [first ,second]: v) {
                if(max_val == second) {
                    answer.push_back(first);
                }
            }
        }

    }
    
    sort(answer.begin(), answer.end());

    return answer;
}