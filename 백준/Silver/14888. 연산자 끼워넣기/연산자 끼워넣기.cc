#include <iostream>
#include <algorithm>

using namespace std;

int n;
int num[11];
int op[4];
int min_result = 1000000000;
int max_result = -1000000000;

void bruth_force(int idx, int val) {

    if(idx == n) {
        min_result = min(val, min_result);
        max_result = max(val, max_result);
        return;
    }


    for (int i = 0; i < 4; i++) {
        if(op[i] != 0) {
            op[i]--;
            int tmp;
            if(i == 0) {
                tmp = val + num[idx];
            }
            else if(i == 1) {
                tmp = val - num[idx];
            }
            else if(i == 2) {
                tmp = val * num[idx];
            }
            else if(i == 3) {
                tmp = val / num[idx];
            }
            bruth_force(idx + 1, tmp);
            op[i]++;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    bruth_force(1, num[0]);

    cout << max_result << '\n' << min_result;

}