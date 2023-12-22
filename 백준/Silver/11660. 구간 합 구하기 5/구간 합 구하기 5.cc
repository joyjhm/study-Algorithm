#include<iostream>

using namespace std;

int n, m;
int row1, col1, row2, col2;
int table[1025][1025];
int sum[1025][1025];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> table[i][j];
            if(j == 0) {
                sum[i][j] = table[i][j];
            } else {
                sum[i][j] = sum[i][j - 1] + table[i][j];
            }
            
        }
    }

    for(int i = 0; i < m; i++) {
        int result = 0;
        cin >> row1 >> col1 >> row2 >> col2;
        for (int j = 0; j <= row2 - row1; j++) {
            int a = sum[row2 - j][col2];
            int b = sum[row2 - j][col1 - 1];
            result += sum[row2 - j][col2] - sum[row2 - j][col1 - 1];
        }
        cout << result << '\n';
    }
}