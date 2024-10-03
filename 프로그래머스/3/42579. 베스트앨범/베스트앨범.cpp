#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;


bool compare(pair<string, int> p1, pair<string, int> p2) {
    return p1.second > p2.second;
}

struct pq_compare {
  
    bool operator()(pair<int,int> p1, pair<int,int> p2) {
        if(p1.first == p2.first) {
            return p1.second > p2.second;
        }
        return p1.first < p2.first;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int len = genres.size();
    map<string, int> genres_cnt;
    map<string, priority_queue<pair<int,int>, vector<pair<int,int>>, pq_compare>> m;
    vector<pair<string, int>> v;
    
    for (int i = 0; i < len; i++) {
        string target_genres = genres[i];
        int target_plays = plays[i];
        
        genres_cnt[target_genres] += target_plays;
        m[target_genres].push({target_plays, i});
    }
    
    for (auto iter = genres_cnt.begin(); iter != genres_cnt.end(); iter++) {
        v.push_back({iter -> first, iter -> second});
    }
    
    sort(v.begin(), v.end(), compare);
    
    
    for (int i = 0; i < v.size(); i++) {
        int cnt = 0;
        string genre = v[i].first;

        while(cnt != 2 && !m[genre].empty()) {
            int idx = m[genre].top().second;
            m[genre].pop();
            answer.push_back(idx);
            cnt++;        
        }
    }
    
    return answer;
}