#include <iostream>
#include <vector>
using namespace std;

int main () {

    int n, m;
    cin >> n >> m;
    vector<int> sum(n + 1, 0);
    vector<int> rest[m];
    
    long long result = 0;
    int tmp;

    rest[0].push_back(0);
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        sum[i] = sum[i - 1] + tmp;
        if (sum[i] >= m) {
            sum[i] = sum[i] % m;
        }
        rest[sum[i]].push_back(i);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < rest[i].size(); j++) {
            result += j;
        }

    }
    
    cout << result;
}