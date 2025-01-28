#include <iostream>
#include <algorithm>
using namespace std;
vector<int> v;
int lesson[100001];
int n, m;

bool isValidBluRaySize(int val) {
    int sum = 0;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        if (sum + lesson[i] > val) {
            cnt++;
            sum = 0;
        }
        sum += lesson[i];
    }
    return cnt <= m;
}

int main() {
    cin >> n >> m;
    int start = 0;
    int end = 0;

    for (int i = 0; i < n; i++) {
        cin >> lesson[i];
        end += lesson[i];
        start = max(start, lesson[i]);
    }

    int result = end;

    while(start <= end) {
        int mid = (start + end) / 2;
        if (isValidBluRaySize(mid)) {
            result = min(result, mid);
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    cout << result;
}