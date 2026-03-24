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
    int ones = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num > 1) {
            plus.push_back(num);
        }
        else if(num == 1) {
            ones++;
        }
        else if (num == 0) {
            hasZero = true;
        }
        else {
            minus.push_back(num);
        }
    }

    sort(plus.begin(), plus.end(), greater<int>());
    sort(minus.begin(), minus.end());

    int sum = 0;

    for (int i = 0; i + 1 < plus.size(); i += 2) {
        sum += plus[i] * plus[i + 1];
    }
    if(plus.size() % 2 != 0) {
        sum += plus.back();
    }    
    sum += ones;

    for (int i = 0; i + 1< minus.size(); i += 2) {
        sum += minus[i] * minus[i + 1];
    }    

    if(minus.size() % 2 != 0 && !hasZero) {
        sum += minus.back();
    }

    cout << sum;
}