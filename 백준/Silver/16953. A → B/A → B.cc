#include<iostream>
#include<queue>
using namespace std;

long long a, b;
queue<pair<long long, int>> q;
int result = 0;

int main() {

    cin >> a >> b;
    q.push({a, 1});

    while(!q.empty()) {

        long long value = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(value == b) {
            result = cnt;
            break;
        }

        if(value * 2 <= b && value * 2 <= 1000000000) {
            q.push({value * 2, cnt + 1});
        }
        if(value * 10 + 1 <= b && value * 10 + 1 <= 1000000000) {
            q.push({value * 10 + 1, cnt + 1});
        }
    }
    if(result != 0) {
        cout << result;
    }
    else {
        cout << -1;
    }
}