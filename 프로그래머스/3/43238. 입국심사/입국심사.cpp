#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <iostream> 

using namespace std;

bool check(int n, long long mid, vector<int>& times) {
    long long cnt = 0;
    for (int i = 0; i < times.size(); i++) {
        if(mid >= times[i]) {
            cnt += mid / times[i];
            if (cnt >= n) {
                return true;
            }
        }
        else {
            break;
        }
    }
    if(cnt >= n) {
        return true;
    }
    else {
        return false;
    }
}


long long solution(int n, vector<int> times) {
    long long answer = 0;
        
    sort(times.begin(), times.end());
    
    long long start = 0;
    long long end = 1000000000000000;
    while(start < end) {
        long long mid = (start + end) / 2;
        if(!check(n, mid, times)) {
            start = mid + 1;
        }   
        else {
            answer = mid;
            end = mid;
        }

    }

    return answer;
}