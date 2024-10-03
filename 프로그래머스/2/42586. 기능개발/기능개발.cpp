#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int len = speeds.size();
    int day = 0;
    queue<int> q;
    for (int i = 0; i < len; i++) {
        int rest = 100 - progresses[i];    
        int day = rest / speeds[i];
        if(rest % speeds[i]) {
            day++;
        }
        q.push(day);
    }
    
    while(!q.empty()) {
        int day = q.front();
        int cnt = 1;
        q.pop();
        
        while(q.front() <= day && !q.empty()) {
            cnt++;
            q.pop();
        }
        
        answer.push_back(cnt);
    }
    
    
    return answer;
}