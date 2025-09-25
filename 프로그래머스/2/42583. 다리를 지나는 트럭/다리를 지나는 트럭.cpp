#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;

    queue<pair<int,int>> q;
    int current_weight = 0;
    int n = truck_weights.size();
    int idx = 0;

    while(!q.empty() || idx < n) {
        time++;
        if(q.empty()) {
            q.push({truck_weights[idx], time});
            current_weight += truck_weights[idx];
            idx++;
        } 
        else {
            int size = q.front().first;        
            int moment = q.front().second;
            
            if(time - moment >= bridge_length) {
                q.pop();
                current_weight -= size;   
            }
         
           if(idx < n && current_weight + truck_weights[idx] <= weight) {
               q.push({truck_weights[idx], time});
               current_weight += truck_weights[idx];
               idx++;
            }    
        }
        
    }
    
    return time;
}