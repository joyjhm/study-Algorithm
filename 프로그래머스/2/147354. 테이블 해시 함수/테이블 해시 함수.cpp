#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int c;

bool compare(vector<int>& v1, vector<int>& v2) {
    
    if(v1[c - 1] == v2[c - 1]) {
        return v1[0] > v2[0];
    }
    return v1[c - 1] < v2[c - 1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    c = col;

    sort(data.begin(), data.end(), compare);

    for (int i = row_begin - 1; i < row_end; i++) {
        int sum = 0;
        for (int j = 0; j < data[i].size(); j++) {
            sum += data[i][j] % (i + 1);
        }   
        answer = (sum ^ answer);
    }
    
    return answer;
}

