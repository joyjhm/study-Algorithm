#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> wait_jobs;     
int answer = 0;
int current_time = 0;
int cnt = 0;

void job() {
    
    int work_time = wait_jobs.top().first;
    int start_time = wait_jobs.top().second;  
    wait_jobs.pop();
    
    int wait_time = current_time - start_time;    

    
    current_time += work_time;
    answer += work_time + wait_time;
        
    cnt++;
}


int solution(vector<vector<int>> jobs) {
    int index = 0;
    // (작업의 소요시간, 작업에 요청되는 시점)
    
    sort(jobs.begin(), jobs.end());
    
    while(cnt != jobs.size()) {
        for (int i = index; i < jobs.size(); i++) {
            if(jobs[i][0] <= current_time) {
                wait_jobs.push({jobs[i][1], jobs[i][0]});
                index = i + 1;
            } 
            else {
                index = i;
                break;
            }
        }
        
        if(wait_jobs.empty()) {
            current_time++;
        }
        else {
            job();
        }
    }
    
    answer = answer / jobs.size();
    
    return answer;
}