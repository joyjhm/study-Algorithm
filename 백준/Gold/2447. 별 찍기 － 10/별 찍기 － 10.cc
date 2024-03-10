#include <iostream>

using namespace std;

char star[6562][6562];

void recursion(int n, bool blank, int row, int col) {





    if(n < 3) {
        if(blank) {
            star[row][col] = ' ';
            return;
        }
        else {
            star[row][col] = '*';
            return;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(blank) {
                recursion(n / 3, true, row + i * n / 3, col + j * n / 3);
                
            } else {
                if(i == 1 && j == 1) {
                    recursion(n / 3, true, row + i * n / 3, col + j * n / 3);
                } else {
                    recursion(n / 3, false, row + i * n / 3, col + j * n / 3);
                }
            }

        }
    }

}


int main() {

    int n;
    cin >> n;

    recursion(n, false, 0, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << star[i][j];
        }
        cout << '\n';
    }
}