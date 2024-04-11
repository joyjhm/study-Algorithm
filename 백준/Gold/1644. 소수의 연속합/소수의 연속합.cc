#include <iostream>
#include <vector>

using namespace std;

int arr[4000001];

int main() {

    int n;
    cin >> n;
    vector<int> prime_num;
    for (int i = 2; i <= n; i++) {
        if(arr[i] == -1) {
            continue;
        }

        for (int j = 2 * i; j <= n; j = j + i) {
            arr[j] = -1;
        }

    }

    for (int i = 2; i <= n; i++) {
        if(arr[i] == 0) {
            prime_num.push_back(i);
        }
    }

    int start, end, cnt, sum;
    start = end = sum = cnt = 0;

    for (int i = 0; i < prime_num.size(); i++) {
        sum += prime_num[i];
        if(sum < n) {
            end++;
        }
        while(sum > n) {
            sum -= prime_num[start];
            start++;                
        }
        if (sum == n) {
            cnt++;
        }
    }

    cout << cnt;

}