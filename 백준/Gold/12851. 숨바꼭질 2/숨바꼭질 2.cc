#include<iostream>
#include<queue>

using namespace std;

int n, k;
int visited[100001];
queue<pair<int, int>> q;
int result = 10000000;
int cnt = 0;
int main() {

    cin >> n >> k;

    q.push({0, n});

    while(!q.empty()) {
        int second = q.front().first;
        int cur = q.front().second;
        q.pop();

        if(result < second) {
            continue;
        }

        if (cur == k) {
            result = second;
            if (second == result) {
                cnt++;
            }
            continue;
        }
        
        if (cur - 1 >= 0 && (visited[cur - 1] == 0 || second + 1 <= visited[cur - 1])) {
            visited[cur - 1] = second + 1;
            q.push({second + 1, cur - 1});
        }
        if (cur + 1 <= 100000 && (visited[cur + 1] == 0 || second + 1 <= visited[cur + 1])) {
            visited[cur + 1] = second + 1;
            q.push({second + 1, cur + 1});
        }
        if (cur * 2 <= 100000 && (visited[cur * 2] == 0 || second + 1 <= visited[cur * 2])) {
            visited[cur * 2] = second + 1;
            q.push({second + 1, cur * 2});
        }

    }

    cout << result << '\n';
    cout << cnt;


}


// 4 6 10
// 3 5 8  5 7 12  9 11 20 