#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;


deque<char> wheel[5];
queue<pair<int, int>> q;


void right_wheel(int idx, int dir) {
    while(idx <= 4) {
        if (idx <= 4 && wheel[idx - 1].at(2) != wheel[idx].at(6)) {
            dir = -dir;
            q.push({idx, dir});
        } else {
            break;
        }
        idx++;
    }
}

void left_wheel(int idx, int dir) {
    while(idx > 0) {
        if (idx > 0 && wheel[idx + 1].at(6) != wheel[idx].at(2)) {
            dir = -dir;
            q.push({idx, dir});
        } else {
            break;
        }
        idx--;
    }
}

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

        q.push({idx, dir});
        right_wheel(idx + 1, dir);
        left_wheel(idx - 1, dir);

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