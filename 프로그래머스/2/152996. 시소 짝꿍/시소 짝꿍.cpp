#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    int n = weights.size();

    vector<int> v(1001);

    for (int i = 0; i < n; i++) {
        v[weights[i]]++;
    }

    for (int i = 100; i <= 1000; i++) {
        // 같을 때
        if(v[i] > 0) {
            if(v[i] >= 2) {
                answer += ((long long)v[i] * (v[i] - 1)) / 2;  
            }
            // 2:4일 때
            if(i * 2 <= 1000) {
                answer += (long long) v[i * 2] * (long long) v[i];    
            }
            // 2:3일 때
            if((i * 3) % 2 == 0 && (i * 3) / 2 <= 1000) {
                answer += (long long) v[i] * v[(i * 3) / 2];       
            }
            // 3:4일 때
            if((i * 4) % 3 == 0 && (i * 4) / 3 <= 1000) {
                answer += (long long) v[i] * v[(i * 4) / 3];      
            }            
        }

        
    }

    return answer;
}