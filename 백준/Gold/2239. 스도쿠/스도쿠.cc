#include <iostream>

using namespace std;

char sdoku[9][9];
bool finish;

bool check(int y, int x, int val) {

    char c = '0' + val;

    for (int i = 0; i < 9; i++) {
        if(sdoku[y][i] == '0' + val || sdoku[i][x] == '0' + val) {
            return false;
        }
    }

    int tx = x / 3 * 3;
    int ty = y / 3 * 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 ; j++) {
            if(sdoku[ty + i][tx + j] == '0' + val) {
                return false;
            }
        }
    }

    return true;

}

void solve(int y, int x) {

    if (finish) {
        return;
    }

    if(x == 9) {
        solve(y + 1, 0);
        return;
    }

    if (y == 9) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sdoku[i][j];
            }
            cout << '\n';
        }
        finish = true;
    }

    if (sdoku[y][x] == '0') {
        for (int k = 1; k <= 9; k++) {
            if(check(y, x, k)) {
                sdoku[y][x] = '0' + k;
                solve(y, x + 1);
                sdoku[y][x] -= k;
            }
        }
        return;
    } else {
        solve(y, x + 1);
    }
}

int main() {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sdoku[i][j];
        }
    }

    solve(0, 0);

}