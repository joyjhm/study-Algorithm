#include<iostream>

using namespace std;

int n, m;
int num;
int sum[100001];
int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> num;
        sum[i] = sum[i - 1] +  num;
    }
    int i, j;
    while(m--) {
        cin >> i >> j;
        int result = 0;
        result = sum[j] - sum[i - 1];
        cout << result << '\n';
    }

}