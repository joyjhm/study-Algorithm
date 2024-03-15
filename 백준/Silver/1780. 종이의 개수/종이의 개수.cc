#include<iostream>

using namespace std;

int paper[2187][2187];
int result[3];


void recursion(int n, int row, int col) {

    int num = paper[row][col];

    for (int i = row; i < row + n; i++) {
        for (int j = col; j < col + n; j++) {
            if(paper[i][j] != num) {
                recursion(n / 3, row, col);
                recursion(n / 3, row, col + n / 3);
                recursion(n / 3, row, col + n / 3 * 2);
                recursion(n / 3, row + n / 3, col);
                recursion(n / 3, row + n / 3, col + n / 3);
                recursion(n / 3, row + n / 3, col + n / 3 * 2);
                recursion(n / 3, row + n / 3 * 2, col);
                recursion(n / 3, row + n / 3 * 2, col + n / 3);
                recursion(n / 3, row + n / 3 * 2, col + n / 3 * 2);
                return;
            }
        }
    }

    result[num + 1]++;
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }

    recursion(n, 0, 0);
    for (int i= 0; i < 3; i++) {
        cout << result[i] << '\n';
    }
}