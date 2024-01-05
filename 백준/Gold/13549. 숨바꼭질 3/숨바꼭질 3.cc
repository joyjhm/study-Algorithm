#include<iostream>
#include<queue>

using namespace std;

int n, k;
int second = 0;
int point[100001];
bool visited[100001];
queue<int> q;
int main() {

    cin >> n >> k;
    if (n == k) {
        cout << 0;
        return 0;
    }
    q.push(n);
    while(!visited[k]) {
        int target = q.front();
        q.pop();

        if(2 * target <= 100000 && !visited[2 * target]) {
            visited[2 * target] = true;
            q.push(2 * target);
            point[2 * target] = point[target];
        }

        if(target - 1 >= 0 && !visited[target - 1]) {
            visited[target - 1] = true;
            q.push(target - 1);
            point[target - 1] = point[target] + 1;
        }
        if(target + 1 <= 100000 && !visited[target + 1]) {
            visited[target + 1] = true;
            q.push(target + 1);
            point[target + 1] = point[target] + 1;
        }
          
    }

    cout << point[k];

}