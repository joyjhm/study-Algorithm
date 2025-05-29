#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    int len = order.size();
    int idx = 0;
    int container_idx = 1;
    
    while(idx < len) {
        if(order[idx] > container_idx) {
            s.push(container_idx);
            container_idx++;
        }
        else {
            if(container_idx == order[idx]) {
                idx++;
                answer++;
                container_idx++;
            }
            else if(!s.empty() && order[idx] == s.top()){
                s.pop();
                idx++;
                answer++;
            }
            else {
                break;
            }
        }
        
        
    }
    
    while(!s.empty()) {
        if(order[idx] == s.top()) {
            s.pop();
            idx++;
            answer++;
        }
        else {
            break;
        }
    }

    
    return answer;
}