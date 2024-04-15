#include <iostream>
using namespace std;

int maps[100][100];
int n, l;
int cnt;

bool col(int y, int x) {

    int plus = 1;
    int minus = 0;
    x++;
    while (x < n) {

        if(0 < minus && minus < l) {
            if(maps[y][x] == maps[y][x - 1]) {
                minus++;
            } else {
                return false;
            }
        }
        else if(maps[y][x] == maps[y][x - 1]) {
            plus++;
        }
        else if (maps[y][x] - maps[y][x - 1] == -1) { // 3 -> 2
            minus++;
        }
        else if (maps[y][x] - maps[y][x - 1] == 1) { // 2 -> 3
            if(plus >= l && minus == 0) {
                plus = 1;
            } else {
                return false;
            }
        }
        else {
            return false;
        }
        x++;
        if(minus == l) {
            minus = 0;
            plus = 0;
        }


    }
    
    if(minus != 0) {
        return false;
    }
    return true;
}

bool row(int y, int x) {

    int plus = 1;
    int minus = 0;
    y++;
    while (y < n) {

        if(0 < minus && minus < l) {
            if(maps[y][x] == maps[y - 1][x]) {
                minus++;
            } else {
                return false;
            }
        }
        else if(maps[y][x] == maps[y - 1][x]) {
            plus++;
        }
        else if (maps[y][x] - maps[y - 1][x] == -1) { // 3 -> 2
            minus++;
        }
        else if (maps[y][x] - maps[y - 1][x] == 1) { // 2 -> 3
            if(plus >= l && minus == 0) {
                plus = 1;
            } else {
                return false;
            }
        }
        else {
            return false;
        }
        y++;
        if(minus == l) {
            minus = 0;
            plus = 0;
        }


    }
    
    if(minus != 0) {
        return false;
    }
    return true;
}


int main() {

    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maps[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        if(col(i, 0)) {
            cnt++;
        }
    }

    for (int i = 0; i < n; i++) {
        if(row(0 , i)) {
            cnt++;            
        }
    }

    cout << cnt;

}