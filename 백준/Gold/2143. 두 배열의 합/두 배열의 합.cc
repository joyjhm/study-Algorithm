#include <iostream>
#include <map>
using namespace std;

int a[1001];
int b[1001];

map<int,int> sum_a;

int main() {

    int t;
    cin >> t;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        a[i] = a[i - 1] + tmp;
    }

    int m;
    cin >> m;

    for (int i = 1; i <= m; i++) {
        int tmp;
        cin >> tmp;
        b[i] = b[i - 1] + tmp;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int sum = a[j] - a[j - i];
            sum_a[sum]++;
        }
    }

    long long result = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            int sum = b[j] - b[j - i];
            if (sum_a[t - sum]) {
                result += sum_a[t - sum];
            }
        }
    }

    cout << result;

}