#include<iostream>

using namespace std;

int triangle[500][500];
int dp[500][500];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size, number;
    cin >> size;


    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> number;
            triangle[i][j] = number;
        }
    }

    dp[0][0] = triangle[0][0];

    for (int i = 1; i < size; i++) {
        for (int j = 0; j <= i; j++) {

            if (j == 0) {
                dp[i][j] = dp[i - 1][0] + triangle[i][j];
            }

            if (j == i) {
                dp[i][j] = dp[i- 1][j - 1] + triangle[i][j];

            }

            dp[i][j] = max(dp[i - 1][j - 1] + triangle[i][j], dp[i - 1][j] + triangle[i][j]); 
        
        }

    }
    int max = dp[size - 1][0]; 
    for (int i = 1; i < size; i++) {
        if (max < dp[size - 1][i]) {
            max = dp[size - 1][i];
        }
    }

    cout << max;

}