#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double> area;
    int x = 0;
    while(k != 1) {
        int y = k;
        if(k % 2 == 0) {
            k /= 2;
        }
        else {
            k = k * 3 + 1;
        }
        area.push_back((double)(y + k)  / 2);
        x++;
    }
    int n = area.size();
    vector<double> sum(n + 1);
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i - 1] + area[i - 1];
    }
     
    for (int i = 0; i < ranges.size(); i++) {
        int start = ranges[i][0];
        int end = x + ranges[i][1];
        if(start > end) {
            answer.push_back(-1.0);
        }
        else if(start == end) {
            answer.push_back(0);
        }
        else {
            answer.push_back(sum[end] - sum[start]); 
        }
    }

    return answer;
}