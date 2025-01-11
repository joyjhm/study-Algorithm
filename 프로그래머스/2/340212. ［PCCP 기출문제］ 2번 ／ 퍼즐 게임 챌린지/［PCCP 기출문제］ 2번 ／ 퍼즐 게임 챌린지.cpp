#include <string>
#include <vector>

using namespace std;

int len;

long long cal_time(vector<int>& diffs, vector<int>& times, int level) {

    long long total_time = 0;
    
    for (int i = 0; i < len; i++) {
        if(level >= diffs[i]) {
            total_time += times[i];
        } else {
            total_time += (times[i - 1] + times[i]) * (diffs[i] - level) + times[i];
        } 
    }
    return total_time;
}


int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    len = diffs.size();
    
    long long start = 1;
    long long end = limit;
    long long mid;

    while(start <= end) {
        mid = (start + end) / 2;            
        long long total_time = cal_time(diffs, times, mid);
        
    
        if(total_time <= limit) {
            answer = mid;
            end = mid - 1;
        }

        else {
            start = mid + 1;
        }
    
    }
    
    
    return answer;
}