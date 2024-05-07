#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

int arr[501][501];
int sum[501];

int dp(int a, int b) {

    if (a == b) {
        return 0;
    }
    int& ret = arr[a][b];
    if (ret) {
        return arr[a][b];
    }
    ret = INT_MAX;

    for (int m = a; m <= b - 1; m++) {
        ret = min(arr[a][b], dp(a, m) + dp(m + 1, b) + sum[b] - sum[a- 1]);
    }

    return ret;
}



int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int k;
        cin >> k;

        for (int i = 1; i <= k; i++) {
            int tmp;
            cin >> tmp;
            sum[i] = sum[i - 1] + tmp;
        }
        int result = INT_MAX;
        result = dp(1, k);

        cout << result << '\n';
        memset(arr, 0, sizeof(arr));
        memset(sum, 0, sizeof(sum));
    }

}

