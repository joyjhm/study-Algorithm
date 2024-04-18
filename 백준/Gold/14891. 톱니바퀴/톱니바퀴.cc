#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;


deque<char> wheel[5];

int main() {

    int k;

    for (int i = 1; i <=4; i++) {
        for (int j = 0; j < 8; j++) {
            char tmp;
            cin >> tmp;
            wheel[i].push_back(tmp);
        }
    }

    cin >> k;

    for (int i = 0; i < k; i++) {
        int idx, dir;
        cin >> idx >> dir;

        queue<pair<int, int>> q;
        int right = (idx + 1);
        int left = (idx - 1);

        q.push({idx, dir});
        int right_dir = dir;
        int left_dir = dir;
        while(right <= 4) {
            if (right <= 4 && wheel[right - 1].at(2) != wheel[right].at(6)) {
                right_dir = -right_dir;
                q.push({right, right_dir});
            } else {
                break;
            }
            right++;
        }
        while(left > 0) {
            if (left > 0 && wheel[left + 1].at(6) != wheel[left].at(2)) {
                left_dir = -left_dir;
                q.push({left, left_dir});
            } else {
                break;
            }
            left--;
        }

        while(!q.empty()) {
            idx = q.front().first;
            dir = q.front().second;
            q.pop();
            if(dir == 1) {  // 시계
                char tmp = wheel[idx].back();
                wheel[idx].pop_back();
                wheel[idx].push_front(tmp);
                } else {    // 반시계
                char tmp = wheel[idx].front();
                wheel[idx].pop_front();
                wheel[idx].push_back(tmp);
            }
        }
    }
    int result = 0;
    for (int i = 1; i <= 4; i++) {
        if (wheel[i].at(0) == '1') {
            result += pow(2, i - 1);
        }
    }

    cout << result;
}