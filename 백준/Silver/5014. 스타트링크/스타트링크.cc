#include <iostream>
#include <queue>
using namespace std;

// f: 총 층 수
// s: 시작 층
// g: 목표 층
// u: 위 버튼
// d: d 버튼
int f,s,g,u,d;
int visited[1000001];
queue<int> q;

int main() {
    cin >> f >> s >> g >> u >> d;

    q.push(s);

    while(!q.empty()) {
        int pos = q.front();
        int cnt = visited[pos];
        q.pop();

        int up = pos + u;
        int down = pos - d;

        if(pos == g) {
            cout << visited[g];

            return 0;
        }


        if(up <= f && !visited[up] && up != pos) {
            visited[up] = visited[pos] + 1;
            q.push(up);
        }

        if(down > 0 && !visited[down] && down != pos) {
            visited[down] = visited[pos] + 1;
            q.push(down);
        }
    }

    cout << "use the stairs";
}