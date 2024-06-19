#include <iostream>
#include <queue>
using namespace std;

int main() {

    int a, b, c, n;
    cin >> a >> b >> c >> n;

    queue<int> q;

    bool visited[301] = {false, };
    q.push(n);

    while(!q.empty()) {

        int cur = q.front();
        q.pop();

        if (cur == 0) {
            cout << 1;
            return 0;
        } 

        if (cur - a >= 0 && !visited[cur - a]) {
            visited[cur - a] = true;
            q.push(cur - a);
        }
        if (cur - b >= 0 && !visited[cur - b]) {
            visited[cur - b] = true;
            q.push(cur - b);
        }
        if (cur - c >= 0 && !visited[cur - c]) {
            visited[cur - c] = true;
            q.push(cur - c);
        }
    }

    cout << 0;

}