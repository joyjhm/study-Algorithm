#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int len = A.size();
    int b_idx = 0;
    
    for (int i = 0; i < len; i++) {
        while(b_idx < len && A[i] >= B[b_idx]) {
            b_idx++;
        }
        if(b_idx >= len) {
            break;
        } else {
            answer++;
            b_idx++;
        }
        
        
    }
    
    return answer;
}