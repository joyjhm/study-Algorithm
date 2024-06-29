#include <iostream>

using namespace std;

char arr[402][404];
int col, row;

int target_y;
int target_x;


int left(int x, int y) {

    arr[y][x] = '*';
    x--;

    while(true) {
        if(arr[y][x] == '*') {
            arr[y][x + 1] = '-';
            x = x + 2;
            break;
        }
        else if(x == 0) {
            x = x + 1;
            break;
        }
        else {
            arr[y][x] = '*';
        }
        x--;
    }

    return x;
}

int down(int x, int y) {

    arr[y][x] = '*';
    y++;

    while(true) {
        if(arr[y][x] == '*') {
            arr[y - 1][x] = '-';
            y = y - 2;
            break;
        }
        else if(y == row + 1) {
            y = y - 1;
            break;
        }
        else {
            arr[y][x] = '*';
        }
        y++;
    }
    
    return y;
}

int right(int x, int y) {

    arr[y][x] = '*';
    x++;

    while(true) {
        if(arr[y][x] == '*') {
            arr[y][x - 1] = '-';
            x = x - 2;
            break;
        }
        else if(x == col + 1) {
            x = x - 1;
            break;
        }
        else {
            arr[y][x] = '*';
        }
        x++;
    }

    return x;
}

int up(int x, int y) {

    arr[y][x] = '*';
    y--;

    while(true) {

        if(arr[y][x] == '*') {
            arr[y + 1][x] = '-';
            y = y + 2;
            break;
        }
        else if(y == 0) {
            y = y - 1;
            break;
        }
        else {
            arr[y][x] = '*';
        }
        y--;
    }

    return y;

}


int main() {

    int n;
    cin >> n;

    if(n == 1) {
        cout << '*';
        return 0;
    }

    col = 1 + 4 * (n - 1);
    row = col + 2;

    int x = col;
    int y = 1;

    while(true) {
        x = left(x, y);
        y = down(x, y);

        if(x == (1 + col) / 2) {
            break;
        }
        x = right(x, y);
        y = up(x, y);
    }


    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            if(i == 2 && j > 1) {
                continue;
            }
            else if(!arr[i][j] || arr[i][j] == '-') {
                cout << ' ';
            }
            else {
                cout << arr[i][j];
            }
        }
        cout << '\n';
    }

}
