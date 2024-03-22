#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int cnt[11];

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    int priority = priorities[location];
    int max_priority = priority;
    cnt[priority]++;
    priorities[location] = 0;
    
    for (int i = 0; i < priorities.size(); i++) {
        int temp = priorities[i];
        max_priority = max(max_priority, temp);
        cnt[temp]++;
        q.push(temp);
    }

    while(!q.empty()) {
        int temp = q.front();
        if(temp == 0 && priority == max_priority) {
            answer++;
            break;
        }
        
        if(max_priority == temp) {
            answer++;
            q.pop();
            cnt[max_priority]--;
            
            while(cnt[max_priority] == 0) {
                max_priority--;
            }

        } else {
            q.pop();
            q.push(temp);
        }  
    }
    
    return answer;
}