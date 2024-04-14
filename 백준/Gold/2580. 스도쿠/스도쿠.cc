#include <iostream>

using namespace std;

int board[9][9];
bool isPrint;

void print() {

    if(isPrint)
        return;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    isPrint = true;
}

void sdoku(int y, int x) {

    if(!board[y][x]) {
        bool visited[10] = {false, };

        for (int i = 0; i < 9; i++) {
            int row = board[y][i];
            int col = board[i][x];

            visited[row] = true;
            visited[col] = true;
        }

        int range_y = y / 3 * 3;
        int range_x = x / 3 * 3;

        for (int i = range_y; i < range_y + 3; i++) {
            for (int j = range_x ; j < range_x + 3; j++) {
                visited[board[i][j]] = true;
            }
        }

        for (int i = 1; i <= 9; i++) {
            if(!visited[i]) {
                board[y][x] = i;
            if(x == 8 && y == 8) {
                print();
            } else if(x == 8) {
                sdoku(y + 1, 0);
            } else {
                sdoku(y, x + 1);
            }  
                board[y][x] = 0;
            }
        }
    }
    else {
        if(x == 8 && y == 8) {
            print();
        } else if(x == 8) {
            sdoku(y + 1, 0);
        } else {
            sdoku(y, x + 1);
        }
    }

}

int main() {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    sdoku(0, 0);
}