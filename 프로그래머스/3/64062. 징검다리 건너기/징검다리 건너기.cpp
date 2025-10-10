#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool getVal(int num, int k, vector<int>& stones) {
    int cnt = 0;
    for (int i = 0; i < stones.size(); i++) {
        if(stones[i] - num > 0) {
            cnt = 0;
        }
        else {
            cnt++;
        }
        
        if(cnt == k) {
            return false;
        }
    }
    return true;
}


int solution(vector<int> stones, int k) {
    int answer = 0;

    int n = stones.size();
    cout << "n: " << n << '\n';
    int start = 0;
    int end = 200000000;
    
    while(start <= end) {
        int mid = (start + end) / 2;
        bool isPossible = getVal(mid, k, stones);

        if(isPossible) {
            answer = mid;
            start = mid + 1;
        }
        else {
           end = mid - 1; 
        }
    }


    return answer + 1;
}