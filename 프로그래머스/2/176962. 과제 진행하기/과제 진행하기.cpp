#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct Info {
    int time;
    int rest;
    string name;
};

struct compare {
    bool operator()(Info& i1, Info& i2) {
        return i1.time < i2.time;
    }
};

int timeToInt(string time) {
    
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3));
    
    return hour * 60 + minute;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    priority_queue<Info, vector<Info>, compare> pq;
    int n = plans.size();
    vector<Info> custom_plans(n);

    for (int i = 0; i < n; i++) {
        string name = plans[i][0];
        int start = timeToInt(plans[i][1]);
        int rest = stoi(plans[i][2]);
        custom_plans[i] = {start, rest, name};        
    }

    sort(custom_plans.begin(), custom_plans.end(), [](Info& i1, Info& i2) {
        return i1.time < i2.time;
    });

    int idx = 0;
    int time = 0;

    bool hasCur = false;
    Info cur;   

    while(idx != n) {
        if(custom_plans[idx].time > time) {
            if(!hasCur) {
                if(!pq.empty()) {
                    cur = pq.top();
                    pq.pop();
                    hasCur = true;
                }                  
            }
        }
        else {
            if(hasCur) {
                pq.push(cur);  
            }
            cur = custom_plans[idx];
            idx++;
            hasCur = true;
        }

        if(hasCur) {
            cur.rest--;    
            cur.time = time;
        }
    
        if(hasCur && cur.rest == 0) {
            hasCur = false;
            answer.push_back(cur.name);
        }
        time++;
    }

    if(hasCur) {
        answer.push_back(cur.name);    
    }
    while(!pq.empty()) {
        answer.push_back(pq.top().name);
        pq.pop();
    }
    
    return answer;
}