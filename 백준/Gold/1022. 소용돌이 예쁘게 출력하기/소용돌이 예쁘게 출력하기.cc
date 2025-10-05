#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int n = 1;
int val = 1;
int r1, c1, r2, c2;
int xx;
int yy;

void check(int y, int x ,vector<vector<int>>& v) {

    if(r1 <= y && y <= r2 && c1 <= x && x <= c2) {
        v[yy + y][xx + x] = val;
    }
}

void cycle(int y, int x, vector<vector<int>>& v) {
    // right
    x = x + 1;
    val++;
    check(y, x, v);

    // up
    for (int i = 0; i < n - 2; i++) {
        y = y - 1;
        val++;
        check(y, x, v);
    }

    //left
    for (int i = 0; i < n - 1; i++) {
        x = x - 1;
        val++;
        check(y, x, v);
    }

    //down
    for (int i = 0; i < n - 1; i++) {
        y = y + 1;
        val++;
        check(y, x, v);
    }

    //right
    for (int i = 0; i < n - 1; i++) {
        x = x + 1;
        val++;
        check(y, x, v);
    }
}

int main() {
    cin >> r1 >> c1 >> r2 >> c2;

    int r = r2 - r1 + 1; 
    int c = c2 - c1 + 1;

    vector<vector<int>> v(r, vector<int>(c));

    xx = -c1;
    yy = -r1;

    int y = 0;
    int x = 0;
    n = 3;
    check(0, 0, v);
    

    while(n <= 10001) {
        cycle(y, x, v);
        x++;
        y++;
        n += 2;
    }
    
    int max_val = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            max_val = max(v[i][j] , max_val);
        }
    }

    int len = 0;
    while(max_val) {
        max_val /= 10;
        len++;
    }


    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << setfill(' ') << setw(len) << v[i][j] << " ";
        }
        cout << '\n';
    }

}