#include <iostream>

using namespace std;

int level[6];
int result = 0;

void dfs_case1(int val, int limit, int cnt) {

    if (limit > 10 || cnt > 3) {
        return;
    }

    if(val > result) {
        result = val;
    }

    for (int i = 1; i <= 5; i++) {
        dfs_case1(val + level[i], limit + i, cnt + 1);
    }
    
}

void dfs_case2(int val, int limit, int cnt) {

    if (limit > 15) {
        return;
    }

    if (cnt >= 4) {
        if (val > result) {
            result = val;
        }
    }

    for (int i = 1; i <= 5; i++) {
        dfs_case2(val + level[i], limit + i,  cnt + 1);
    }
}


int main() {

    for (int i = 1; i <= 5; i++) {
        cin >> level[i];
    }

    // 문제가 3 문제 이하인 경우
    dfs_case1(0, 0, 0);
    
    // 문제가 4 문제 이상인 경우

    dfs_case2(0, 0, 0);

    cout << result;

}