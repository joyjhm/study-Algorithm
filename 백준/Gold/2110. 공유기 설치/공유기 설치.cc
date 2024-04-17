#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int search() {
    return 0;
}

int main() {
    int n, c;
    cin >> n >> c;
    vector<int> house(n);    
    for (int i = 0; i < n; i++) {
        cin >> house[i];
    }

    sort(house.begin(), house.end());
    int start = 1;
    int end = house[n - 1] - house[0];
    int result = 0;

    while (start <= end) {
        int mid = (start + end) / 2;    // 간격

        int cur = house[0];
        int cnt = 1;
        for (int i = 0; i < n; i++) {
            if(house[i] - cur >= mid) {
                cnt++;
                cur = house[i];
            }
        }

        if(cnt >= c) {
            start = mid + 1;
            result = max(result, mid);
        } else {
            end = mid - 1;
        } 

    }

    cout << result;


}



