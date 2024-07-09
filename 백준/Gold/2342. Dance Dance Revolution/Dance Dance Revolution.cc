#include <iostream>
#include <algorithm>
#define INF 100000000
using namespace std;

int order[100001];
int dp[100001][5][5];

int main() {

    int idx = 1;
    while(true) {
        int n;
        cin >> n;
        if(n == 0) {
            break;
        }        
        order[idx] = n;
        idx++;
    }


    for (int i = 1; i < idx; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                dp[i][j][k] = INF;
            }
        }
    }

    dp[1][order[1]][0] = 2;
    dp[1][0][order[1]] = 2;

    for (int i = 2; i < idx; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (dp[i - 1][j][k] != INF) {
                    
                    if(order[i] != k) {
                        if(j == 0) {
                            dp[i][order[i]][k] = dp[i - 1][j][k] + 2;
                        }
                        else if(order[i] % 4 == (j + 1) % 4 || order[i] % 4 == (j - 1) % 4) {
                            dp[i][order[i]][k] = min(dp[i][order[i]][k], dp[i - 1][j][k] + 3);
                        }
                        else if(order[i] % 4 == (j + 2) % 4) {
                            dp[i][order[i]][k] = min(dp[i][order[i]][k], dp[i - 1][j][k] + 4);
                        }
                        else if(order[i] % 4 == j % 4) {
                            dp[i][order[i]][k] = min(dp[i][order[i]][k], dp[i - 1][j][k] + 1);
                        }
                    }

                    if(order[i] != j) {

                        if(k == 0) {
                            dp[i][j][order[i]] = dp[i - 1][j][k] + 2;
                        }
                        else if(order[i] % 4 == (k + 1) % 4 || order[i] % 4 == (k - 1) % 4) {
                            dp[i][j][order[i]] = min(dp[i][j][order[i]], dp[i - 1][j][k] + 3);
                        }
                        else if(order[i] % 4 == (k + 2) % 4) {
                            dp[i][j][order[i]] = min(dp[i][j][order[i]], dp[i - 1][j][k] + 4);
                        }
                        else if(order[i] % 4 == k % 4) {
                            dp[i][j][order[i]] = min(dp[i][j][order[i]], dp[i - 1][j][k] + 1);
                        }
                    }



                }
            }
        }
    }

    int result = INF;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            result = min(result, dp[idx - 1][i][j]);
        }
    }

    cout  << result;

}

