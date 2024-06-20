#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int k = 1; k <= t; k++) {
        int n, l;
        cin >> n >> l;

        vector<int> times(n);
        vector<int> finish;
        for (int i = 0; i < n; i++) {
            cin >> times[i];
        }

        sort(times.begin(), times.end());

        int cur, cnt, sum;
        cur = cnt = sum = 0;

        for (int i = 0; i < n; i++) {

            if(times[i] + cur <= l) {
                cur += times[i];
                finish.push_back(cur);
                cnt++;
            }
        }
        
        for (int i = 0; i < finish.size(); i++) {
            sum += finish[i];
        }

        cout << "Case " << k << ": " << cnt << " " << cur << " " << sum << '\n';
    }

}