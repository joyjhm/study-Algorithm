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

void right(int arr[][20]) {

    for (int i = 0; i < n; i++) {

        int idx = n - 1;

        for (int j = n - 1; j >= 0; j--) {

            if(!arr[i][j]) {
                continue;
            }

            if(s.empty()) {
                s.push(arr[i][j]);
            }
            else if(s.top() == arr[i][j]) {
                arr[i][idx] = arr[i][j] * 2;
                s.pop();
                idx--;
            }
            else {
                while(!s.empty()) {
                    arr[i][idx] = s.top();
                    s.pop();
                    idx--;
                }
                s.push(arr[i][j]);
            }
        }

        while(!s.empty()) {
            arr[i][idx] = s.top();
            s.pop();
            idx--;
        }

        while(idx >= 0) {
            arr[i][idx] = 0;
            idx--;
        }
    }

}

void down(int arr[][20]) {

    for (int i = 0; i < n; i++) {

        int idx = n - 1;

        for (int j = n - 1; j >= 0; j--) {
            if(!arr[j][i]) {
                continue;
            }

            if(s.empty()) {
                s.push(arr[j][i]);
            }
            else if(s.top() == arr[j][i]) {
                arr[idx][i] = arr[j][i] * 2;
                s.pop();
                idx--;
            }
            else {
                while(!s.empty()) {
                    arr[idx][i] = s.top();
                    s.pop();
                    idx--;
                }
                s.push(arr[j][i]);
            }
        }

        while(!s.empty()) {
            arr[idx][i] = s.top();
            s.pop();
            idx--;
        }

        while(idx >= 0) {
            arr[idx][i] = 0;
            idx--;
        }

    }
}

void left(int arr[][20]) {

    for (int i = 0; i < n; i++) {

        int idx = 0;

        for (int j = 0; j < n; j++) {
            if(!arr[i][j]) {
                continue;
            }

            if(s.empty()) {
                s.push(arr[i][j]);
            }
            else if(s.top() == arr[i][j]) {
                arr[i][idx] = arr[i][j] * 2;
                s.pop();
                idx++;
            }
            else {
                while(!s.empty()) {
                    arr[i][idx] = s.top();
                    s.pop();
                    idx++;
                }
                s.push(arr[i][j]);
            }
        }

        while(!s.empty()) {
            arr[i][idx] = s.top();
            s.pop();
            idx++;
        }

        while(idx < n) {
            arr[i][idx] = 0;
            idx++;
        }

    }

}

void up(int arr[][20]) {

    for (int i = 0; i < n; i++) {

        int idx = 0;

        for (int j = 0; j < n; j++) {
            if(!arr[j][i]) {
                continue;
            }

            if(s.empty()) {
                s.push(arr[j][i]);
            }
            else if(s.top() == arr[j][i]) {
                arr[idx][i] = arr[j][i] * 2;
                s.pop();
                idx++;
            }
            else {
                while(!s.empty()) {
                    arr[idx][i] = s.top();
                    s.pop();
                    idx++;
                }
                s.push(arr[j][i]);
            }
        }

        while(!s.empty()) {
            arr[idx][i] = s.top();
            s.pop();
            idx++;
        }

        while(idx < n) {
            arr[idx][i] = 0;
            idx++;
        }

    }

}

void move(int dir, int arr[][20]) {

    if(dir == 0) {
        right(arr);
    }
    else if(dir == 1) {
        down(arr);
    }
    else if(dir == 2) {
        left(arr);
    }
    else {
        up(arr);
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

    dfs(0, board);

    cout << result;
}