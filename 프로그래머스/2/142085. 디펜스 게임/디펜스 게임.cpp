#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int, vector<int>> pq;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int len = enemy.size();
    int sum = 0;
    int cnt = 0;
    int i;

    for (i = 0; i < len; i++) {
        int val = enemy[i];
        if(val + sum > n) {
            if(cnt == k) {
                break;
            }
           
            if (!pq.empty() && pq.top() > val) {
                sum -= pq.top() - val;
                pq.pop();
                pq.push(val);
            }
            cnt++;          
        } else {
            pq.push(val);
            sum += val;
        }
        
    }
    answer = i;

    return answer;
}
