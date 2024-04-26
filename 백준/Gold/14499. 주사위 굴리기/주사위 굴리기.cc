#include <iostream>
#include <deque>
using namespace std;

struct Dice {

    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;
    int num5 = 0;
    int num6 = 0;

    int tmp1;
    int tmp2;

    void moveUp() {
        tmp1 = num1;
        tmp2 = num5;

        num1 = num2;
        num2 = num6;
        num5 = tmp1;
        num6 = tmp2;
    }
    void moveDown() {
        tmp1 = num1;
        tmp2 = num2;

        num1 = num5;
        num2 = tmp1;
        num5 = num6;
        num6 = tmp2;
    }

    void moveRight() {
        tmp1 = num1;
        tmp2 = num4;

        num1 = num3;
        num3 = num6;
        num4 = tmp1;
        num6 = tmp2;
    }

    void moveLeft() {
        tmp1 = num1;
        tmp2 = num3;

        num1 = num4;
        num3 = tmp1;
        num4 = num6;
        num6 = tmp2;
    }

    void changeVal(int val) {
        num1 = val;
    }


};

int n, m, x, y, k;
int maps[20][20];

deque<int> dq[3] = {{1, 3, 6, 4}, {1, 5, 6, 2}, {2, 3, 5, 4}};

int main() {
    cin >> n >> m >> y >> x >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maps[i][j];
        }
    }

    Dice dice;
    while(k--) {
        int move;
        int ty, tx;
        cin >> move;
        if (move == 1) {
            tx = 1;
            ty = 0;
        }
        else if (move == 2) {
            tx = -1;
            ty = 0;
        } else if(move == 3) {
            tx = 0;
            ty = -1;
        } else {
            tx = 0;
            ty = 1;
        }

        if(y + ty >= n || x + tx >= m || y + ty < 0 || x + tx < 0)
            continue;
        y = ty + y;
        x = tx + x;

        if(move == 1) {
            dice.moveRight();
        } else if(move == 2) {
            dice.moveLeft();
        } else if(move == 3) {
            dice.moveUp();
        } else {
            dice.moveDown();
        }

        if(maps[y][x] == 0) {
            maps[y][x] = dice.num1;
        } else {
            dice.changeVal(maps[y][x]);
            maps[y][x] = 0;
        }

        cout << dice.num6 << '\n';

    }

}