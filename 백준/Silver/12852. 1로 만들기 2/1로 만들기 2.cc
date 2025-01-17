#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
queue<int> q;
vector<int> v;
int visited[1000001];
int previous[1000001];
int main() {

    cin >> n;
    q.push(n);
    while(!q.empty()) {
        int num = q.front();
        q.pop();

        if(num == 1) {
            break;
        }
        if(num % 3 == 0 && !visited[num / 3]) {
            visited[num / 3] = visited[num] + 1;
            previous[num / 3] = num;
            q.push(num / 3);
        }
        if(num % 2 == 0 && !visited[num / 2]) {
            visited[num / 2] = visited[num] + 1;
            previous[num / 2] = num;
            q.push(num / 2);
        }
        if(num - 1 > 0 && !visited[num - 1]) {
            visited[num - 1] = visited[num] + 1;
            previous[num - 1] = num;
            q.push(num - 1);
        }
    }
    int idx = 1;
    while(idx != n) {
        v.push_back(idx);
        idx = previous[idx];
    }

    cout << visited[1] << '\n' << n << ' ';

    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << ' ';
    }

}