#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long R1 = 1LL * r1 * r1;
    long long R2 = 1LL * r2 * r2;

    
    for (long long x = 1; x <= r2; x++) {
        long long yMax = floor(sqrt(R2 - x * x));

        long long yMin = 0;
        if (x < r1) {
            yMin = ceil(sqrt(R1 - x * x));
        }

        long long start = max(1LL, yMin);
        if (yMax >= start) {
            answer += (yMax - start + 1);
        }
    }
    answer *= 4;
    answer += (r2 - r1 + 1) * 4;

    return answer;
}