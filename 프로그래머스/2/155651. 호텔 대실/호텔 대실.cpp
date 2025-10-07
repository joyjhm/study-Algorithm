#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int strToInt(string str) {
    int hour = stoi(str.substr(0, 2));
    int minute = stoi(str.substr(3, 2));
    return hour * 100 + minute;
}

int addMinute(int time) {
    int addTime = time + 10;
    if(addTime % 100 >= 60) {
        return addTime + 40;
    }
    return addTime;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    int n = book_time.size();

    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++) {
        int start_time = strToInt(book_time[i][0]);
        int end_time = strToInt(book_time[i][1]);
        v.push_back({start_time, end_time});        
    }

    sort(v.begin(), v.end(), [](auto p1, auto p2) {
        if(p1.first == p2.first)
            return p2.second < p1.second;
        return p1.first < p2.first;
    });

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        while(!pq.empty() && addMinute(pq.top()) <= v[i].first) {
            pq.pop();
        }
        pq.push(v[i].second);
        answer = max(answer, (int) pq.size());
    }
    
    return answer;
}