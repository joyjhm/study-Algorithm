#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int answer;

int check(vector<int>& rocks, int n, int target, int distance) {
    int cnt = 0;
    int cur = 0;
    int next = rocks[0];
    int idx = 0;
    
    while(idx < rocks.size()) {
        // cout << cur << " " << next << '\n';
        if(next - cur < target) {
            idx++;
            next = rocks[idx];
            cnt++;
        } else {
            cur = next;
            idx++;
            next = rocks[idx];
        }
    }
    
    if(distance - cur < target) {
        cnt++;
    }
    
    // cout << cnt << " " << target;
    
    if(cnt <= n) {
        // cout << " 성공" << '\n';
        return true;
    }
    else {
        // cout << " 실패" << '\n';
        return false;
    }
}

int search(int distance, vector<int>& rocks, int n) {
    
    int start = 0;
    int end = distance;
    while(start <= end) {
        int mid = (start + end) / 2;
        // cout << start << " " << end  << " " << mid << '\n';
        if(check(rocks, n, mid, distance)) {   
           answer = mid;
           start = mid + 1;
        } 
        else {
            end = mid - 1;
        }
    }

    return answer;
}



int solution(int distance, vector<int> rocks, int n) {
    
    sort(rocks.begin(), rocks.end());
    search(distance, rocks, n);
    
    return answer;
}