#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#define INF 10000

using namespace std;

int n;
int area_num[11];
bool area[11][11];
bool check[11];
int total;
int result = INF;


bool bfs(int cnt) {

    queue<int> q;
    q.push(1);

    bool visited[11] = {false, };
    visited[1] = true;
    int one_cnt = 1;
    

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if(area[cur][i] && !visited[i] && check[i]) {
                visited[i] = true;
                q.push(i);
                one_cnt++;
                
            }
        }
    }

    if(one_cnt != cnt) {
        return false;
    }

    int two_cnt = 0;

    for (int i = 1; i <= n; i++) {
        if(!check[i]) {
            q.push(i);
            two_cnt++;
            visited[i] = true;
            break;
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if(area[cur][i] && !visited[i] && !check[i]) {
                visited[i] = true;
                two_cnt++;
                q.push(i);
            }
        }        
    }

    if (one_cnt + two_cnt == n) {
        return true;
    } else {
        return false;
    }
 
}


void combination(int idx, int val, int cnt) {

    bool isPossible = bfs(cnt);

    if(isPossible) {
        result = min(result, abs(total - val * 2));
    }


    for (int i = idx; i <= n; i++) {
        check[i] = true;
        combination(i + 1, val + area_num[i], cnt + 1);
        check[i] = false;
    }
}

int main() {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> area_num[i];
        total += area_num[i];
    }
    
    for (int i = 1; i <= n; i++) {
        int cnt;
        cin >> cnt;

        for (int j = 0; j < cnt; j++) {
            int tmp;
            cin >> tmp;
            area[i][tmp] = true;
        }
    }

    check[1] = true;
    combination(2, area_num[1], 1);

    
    if(result == INF) {
        cout << -1;
    } else {
        cout << result;
    }
}

