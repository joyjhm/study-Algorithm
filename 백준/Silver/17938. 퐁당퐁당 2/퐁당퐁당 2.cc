#include <iostream>

using namespace std;

int main() {
    int n, p, t;
    cin >> n;
    cin >> p >> t;
    int add = 1;

    int cur = 1;
    int cnt = 2;
    int prev = 0;
    for (int i = 2; i <= t; i++) {
        prev = cur;
        cur += cnt;
        cur %= 2 * n;
        if(cnt == 2 * n) {
            add = -1;
        }
        else if (cnt == 1) {
            add = 1;
        }
        cnt += add;
    }

    if (cur > prev) {
        if ((prev - 1) / 2 <= p - 1  && p - 1 <= (cur - 1) / 2) {
            cout << "Dehet YeonJwaJe ^~^";
        }
        else {
            cout << "Hing...NoJam";
        }
    }
    else {
        if ((prev - 1) / 2 <= p - 1 || p - 1 <= (cur - 1) / 2) {
            cout << "Dehet YeonJwaJe ^~^";
        }
        else {
            cout << "Hing...NoJam";
        }
    }
}


