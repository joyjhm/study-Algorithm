#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;

    // sort(targets.begin(), targets.end());
    sort(targets.begin(), targets.end(), [](const vector<int>& v1, const vector<int>& v2) {
        if(v1[1] == v2[1]) {
            return v1[0] < v2[0];
        }
        return v1[1] < v2[1];
    });

//     for (int i = 0; i < targets.size(); i++) {
//         cout << targets[i][0] << ", " << targets[i][1] << '\n';
//     }
    
    answer = 1;
    int top = targets[0][1] - 1;
    for (int i = 1; i < targets.size(); i++) {
        if(top >= targets[i][0] && top < targets[i][1]) {
            continue;
        }
        else {
            answer++;
            top = targets[i][1] - 1;
        }
    }
    

    return answer;
}