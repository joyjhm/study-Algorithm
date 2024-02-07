#include <iostream>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    
    long long answer = 0;
    long long max_distance = (long long) d * d;

    for (long long i = 0; i * k <= d; i++) {
        long long temp = i * k;
        int dist = sqrt(max_distance - temp * temp);
        answer += dist / k + 1;
    }
    
    return answer;
}