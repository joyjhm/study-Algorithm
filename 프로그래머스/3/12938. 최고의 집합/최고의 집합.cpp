#include <string>
#include <vector>

using namespace std;

 
vector<int> solution(int n, int s) {
    vector<int> answer;
    if (n > s) {
        answer.push_back(-1);
    } else {
        int target = s / n;
        int rest = s % n;
        int cnt = n - rest;
        
        for (int i = 0; i < n; i++) {
            if (i < cnt) {
                answer.push_back(target);
            } else {
                answer.push_back(target + 1);
            }
        }

    }
    
    return answer;
}