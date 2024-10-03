#include <string>
#include <vector>

using namespace std;

int cnt = 0;
int len;
vector<int> arr;
void dfs(int idx, int val, int target) {
    

    if(idx == len) {
        if(val == target) {
            cnt++;        
        }
        return;
    }
    
    
    for (int i = 0; i < 2; i++) {
        if(i == 0) {
            val += arr[idx];
            dfs(idx + 1, val, target);
            val -= arr[idx];
        }
        else {
            val -= arr[idx];
            dfs(idx + 1, val, target);
            val += arr[idx];
        }
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    len = numbers.size();
    arr = numbers;
    
    dfs(0, 0,target);
    return cnt;
}