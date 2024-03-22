#include <string>
#include <vector>

using namespace std;

void col(int brown, int yellow, vector<int> &answer) {
    for (int r = 3; r < 2000; r++) {
        for (int c = 3; c < 2000; c++) {
            if ((c - 2) * (r - 2) == yellow) {
                if (2 * c + (r - 2) * 2 == brown) {
                    answer.push_back(c);
                    answer.push_back(r);
                    return;
                }
            }
        }
    }
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    col(brown, yellow, answer);   
    return answer;
}