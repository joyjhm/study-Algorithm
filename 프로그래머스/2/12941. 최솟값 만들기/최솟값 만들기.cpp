#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int a_start = 0;
    int a_end = A.size() - 1;
    int b_start = 0;
    int b_end = B.size() - 1;
    
    for (int i = 0; i < A.size(); i++) {
        if(a_start * b_end < a_end < b_start) {
            answer += A[a_start] * B[b_end];
            a_start++;
            b_end--;
        }
        else {
            answer += A[a_end] * B[b_start];
            a_end--;
            b_start++;
        }
    }
    

    return answer;
}