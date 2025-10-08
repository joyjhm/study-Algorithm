#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int storey) {
    int answer = 1000000000;
    
    queue<pair<int,int>> q;
    q.push({storey, 0});
    
    while (!q.empty()) {
        auto [val, cnt] = q.front(); 
        q.pop();

        if (val == 0) {
            answer = min(cnt, answer);
            continue;
        }
            
        int d = val % 10;                 
        int down = val - d;               
        int up   = (d == 0) ? val : val + (10 - d); 

        int costDown = d;
        int costUp   = (d == 0) ? 0 : (10 - d);
        
        if(costDown < costUp) {
            q.push({down / 10, cnt + costDown});  
        }
        else if(costDown > costUp){
            q.push({up / 10, cnt + costUp});  
        }
        else {
            q.push({down / 10, cnt + costDown});
            q.push({up / 10, cnt + costUp});
        }
        
        
    }
    return answer;
}