#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ladder[11][31];     // 0은 x, 1은 오른쪽 방향, 2는 왼쪽 방향
int n, m, h;
int result = -1;

bool check() {

    for (int i = 1; i <= n; i++) {
        int idx = i;
        for (int j = 1; j <= h; j++) {
            if(ladder[idx][j] == 1) {
                idx++;
            }
            else if(ladder[idx][j] == 2) {
                idx--;
            }
        }

        if(idx != i) {
            return false;
        }
    }

    return true;    
}

void dfs(int depth, int idx, int pos) {

    if (result != -1 && result < depth) {
        return;
    }


    if(check()) {
        if(result == -1 || result > depth) {
            result = depth;
        }
        return;
    }

    if (depth == 3) {
        return;
    }

    for (int i = idx; i < n; i++) {
        for (int j = 1; j <= h; j++) {
            if(i <= idx && j < pos)
                continue;

            if(ladder[i][j] == 0 && ladder[i + 1][j] == 0) {
                
                ladder[i][j] = 1;
                ladder[i + 1][j] = 2;
                dfs(depth + 1, i, j);
                ladder[i][j] = 0;
                ladder[i + 1][j] = 0;
            }
        }
    }

}

int main() {
    cin >> n >> m >> h;


    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ladder[b][a] = 1;
        ladder[b + 1][a] = 2;
    }

    dfs(0, 1, 1);
    

    cout << result;
    
}