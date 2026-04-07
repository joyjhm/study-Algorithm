#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> scores) {
    
    int n = scores.size();
    int first_score = scores[0][0];
    int second_score = scores[0][1];

    sort(scores.begin() + 1, scores.end(), [](vector<int>& a, vector<int>& b) {
        if(a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] > b[0];
    });

    if(n == 1) {
        return 1;
    }

    int total = first_score + second_score;
    int first = scores[1][0];
    int max_second = scores[1][1];

    int answer = 1;

    for (int i = 1; i < n; i++) {
        bool isPossible = true;

        if(scores[i][1] < max_second) {
            isPossible = false;
        }
        max_second = max(max_second, scores[i][1]);

        if(scores[i][0] - first_score > 0 && scores[i][1] - second_score > 0) {
            answer = -1;
            break;
        }
        else if(first_score - scores[i][0]> 0 && second_score - scores[i][1] > 0) {
            isPossible = false;
        }

        if(isPossible) {
            if (total < scores[i][0] + scores[i][1]) {
                answer++;
            }
        }
    }        


    return answer;
}