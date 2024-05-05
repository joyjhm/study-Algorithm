#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> liquid(n);

    for (int i = 0; i < n; i++) {
        cin >> liquid[i];
    }

    int diff = 2000000001;
    int start = 0;
    int end = n - 1;

    int result1, result2;

    while(start < end) {
        int cur = abs(liquid[start] + liquid[end]);

        if(cur < diff) {
            diff = cur;
            result1 = liquid[start];
            result2 = liquid[end];
        } 

        int tmp1 = abs(liquid[start + 1] + liquid[end]);
        int tmp2 = abs(liquid[start] + liquid[end - 1]);
        if(tmp1 < tmp2) {
            start++;
        } else {
            end--;
        }
    }

    cout << result1 << " " << result2;
}