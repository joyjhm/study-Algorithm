#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int board[20][20];
int n;
stack<int> s;
queue<int> q;
int result;
int dirStart[4];

void right_left(int arr[][20], int dir, int start) {

    for (int i = 0; i < n; i++) {

        int idx = dirStart[start];
        int j = dirStart[start];

        while (j >= 0 && j < n) {

            if(!arr[i][j]) {
                j += dir;
                continue;
            }

            if(s.empty()) {
                s.push(arr[i][j]);
            }
            else if(s.top() == arr[i][j]) {
                arr[i][idx] = arr[i][j] * 2;
                s.pop();
                idx += dir;
            }
            else {
                while(!s.empty()) {
                    arr[i][idx] = s.top();
                    s.pop();
                    idx += dir;

                }
                s.push(arr[i][j]);
            }

            j += dir;
        }

        while(!s.empty()) {
            arr[i][idx] = s.top();
            s.pop();
            idx += dir;

        }

        while(idx >= 0 && idx < n) {
            arr[i][idx] = 0;
            idx += dir;
        }
    }

}

void down_up(int arr[][20], int dir, int start) {

    for (int i = 0; i < n; i++) {

        int idx = dirStart[start];
        int j = dirStart[start];

        while (j >= 0 && j < n) {
            if(!arr[j][i]) {
                j += dir;
                continue;
            }

            if(s.empty()) {
                s.push(arr[j][i]);
            }
            else if(s.top() == arr[j][i]) {
                arr[idx][i] = arr[j][i] * 2;
                s.pop();
                idx += dir;
            }
            else {
                while(!s.empty()) {
                    arr[idx][i] = s.top();
                    s.pop();
                    idx += dir;
                }
                s.push(arr[j][i]);
            }

            j += dir;
        }

        while(!s.empty()) {
            arr[idx][i] = s.top();
            s.pop();
            idx += dir;
        }

        while(idx >= 0 && idx < n) {
            arr[idx][i] = 0;
            idx += dir;
        }

    }
}

void move(int dir, int arr[][20]) {

    if(dir == 0) {
        right_left(arr, -1, 0);
    }
    else if(dir == 1) {
        down_up(arr, -1, 1);
    }
    else if(dir == 2) {
        right_left(arr, 1, 2);
    }
    else {
        down_up(arr, 1, 3);
    }
}

void dfs(int cnt, int arr[][20]) {

    if(cnt == 5) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, arr[i][j]);
            }
        }

        return;
    }

    for (int i = 0; i < 4; i++) {
        int copy_arr[20][20];

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                copy_arr[j][k] = arr[j][k];
            }
        }
        move(i, copy_arr);
        dfs(cnt + 1, copy_arr);
    }

}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        if (i < 2) {
            dirStart[i] = n - 1;
        }
    }

    dfs(0, board);

    cout << result;
}