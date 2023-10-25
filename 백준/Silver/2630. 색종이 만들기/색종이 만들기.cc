#include<iostream>
using namespace std;
int n;
int square[129][129];
int blue = 0;
int white = 0;
int squareNumber(int n, int y, int x) {

    int color = square[y][x];
    for(int i = y; i < y + n; i++) {
        for(int j = x; j < x + n; j++) {
            if(color != square[i][j]) {
                return squareNumber(n/2, y, x) + squareNumber(n/2, y, x + n/2)
                + squareNumber(n/2, y + n/2, x) + squareNumber(n/2, y + n/2, x + n/2);
            }
        }
    }
    if(color == 0){
        white++;
        return 0;
    }
    else {
        blue++;
        return 0;
    }
}

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> square[i][j];
        }
    }
    squareNumber(n,1,1);
    cout << white << endl;
    cout << blue;   

}