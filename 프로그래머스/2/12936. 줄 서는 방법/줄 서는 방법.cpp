#include <string>
#include <vector>
using namespace std;

int getNumber(vector<bool>& visited, int val, int n) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if(!visited[i]) {
            cnt++;
        }
        
        if(cnt == val) {
            return i;
        }
    }
    
    return -1;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;    
    vector<long long> factor(n + 1, 1);
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++) {
        factor[i] = i * factor[i - 1]; 
    }
    
    k--;
    for (int i = n; i >= 1; i--) {  
        long long block = factor[i - 1];
        long long val = k / block;
        k = k % block;
        int num = getNumber(visited, val + 1, n);
        visited[num] = true;
        answer.push_back(num);
        
    }


    return answer;
}