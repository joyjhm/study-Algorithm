#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> plus;
    vector<int> minus;
    bool hasZero = false;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(num > 0) {
            plus.push_back(num);
        }
        else if (num < 0) {
            minus.push_back(num);
        }
        else {
            hasZero = true;
        }
    }

    sort(plus.begin(), plus.end(), greater<int>());
    sort(minus.begin(), minus.end());

    int sum = 0;
    int idx_p, idx_m;
    for (idx_p = 1; idx_p < plus.size(); idx_p += 2) {
        if(plus[idx_p - 1] + plus[idx_p] < plus[idx_p - 1] * plus[idx_p]) {
            sum += plus[idx_p - 1] * plus[idx_p];
        }
        else {
            sum += plus[idx_p - 1] + plus[idx_p];
        }
    }

    for (idx_m = 1; idx_m < minus.size(); idx_m += 2) {
        sum += minus[idx_m - 1] * minus[idx_m];
    }    

    if(plus.size() % 2 != 0) {
        sum += plus[idx_p - 1];
    }    
    if(minus.size() % 2 != 0 && !hasZero) {
        sum += minus[idx_m - 1];
    }

    cout << sum;
}