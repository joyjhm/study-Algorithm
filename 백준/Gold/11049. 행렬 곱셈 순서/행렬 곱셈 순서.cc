#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int arr[501][501];
int matrix[501][2];
int n;


int dp(int a, int b) {

    if (a == b) {
        return 0;
    }


    if(arr[a][b]) {
        return arr[a][b];
    }

    arr[a][b] = INT_MAX;

    for (int m = a; m <= b - 1; m++) {
        int val = matrix[a][0] * matrix[m][1] * matrix[b][1];
        arr[a][b] = min({arr[a][b], dp(a, m) + dp(m + 1, b) + val});
    }

    return arr[a][b];

}

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> matrix[i][0] >> matrix[i][1];
    }
    int result = INT_MAX;
    result = dp(1, n);

    cout << result;


}
