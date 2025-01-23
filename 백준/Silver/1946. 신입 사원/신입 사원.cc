#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n;
int result;

int main() {

    cin >> t;

    while(t--) {
        cin >> n;
        result = 1;
        vector<pair<int,int>> applicant(n);
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++) {
            cin >> applicant[i].first >> applicant[i].second;
        }

        sort(applicant.begin(), applicant.end());

        int idx = 0;

        for (int i = 0; i < n; i++) {
            if (applicant[idx].second > applicant[i].second) {
                result++;
                idx = i;
            }
        }


        cout << result << '\n';
    }
}