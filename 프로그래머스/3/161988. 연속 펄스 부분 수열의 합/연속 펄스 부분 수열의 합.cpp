#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

long long solution(vector<int> sequence) {
    long long answer = LLONG_MIN;

    int n = sequence.size();
    vector<vector<long long>> arr(n, vector<long long>(2));


    long long purse = 1;

    for (int i = 0; i < n; i++) {
        arr[i][0] = (purse * sequence[i]);
        arr[i][1] = (-purse * sequence[i]);
        purse *= -1;
    }

    long long cur1 = 0;
    long long cur2 = 0;

    for (int i = 0; i < n; i++) {
        cur1 = max((long long)arr[i][0], cur1 + arr[i][0]); 
        cur2 = max((long long)arr[i][1], cur2 + arr[i][1]); 
        answer = max({answer, cur1, cur2});
    }

    return answer;
}