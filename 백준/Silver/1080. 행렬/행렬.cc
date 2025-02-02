#include <iostream>

using namespace std;

int n, m;
char a[50][50];
char b[50][50];
int result = 0;

void change(int x, int y) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if((i >= x && i < x + 3) && (j >= y && j < y + 3)) {
                a[i][j] = '1' + '0' - a[i][j];
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if(a[i][j] != b[i][j]) {
                change(i, j);
                result++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(a[i][j] != b[i][j]) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << result;
}