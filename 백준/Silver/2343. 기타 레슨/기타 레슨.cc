#include <iostream>
#include <algorithm>
using namespace std;
vector<int> v;
int lesson[100001];
int n, m;

bool cal(int val) {
    int sum = 0;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        if(lesson[i] > val) {
            return false;
        }
        else if (sum + lesson[i] <= val) {
            sum += lesson[i];
        }
        else {
            cnt++;
            sum = lesson[i];
        }
    }

    if(cnt > m) {
        return false;
    }

    return true;
}

int main() {
    cin >> n >> m;
    int start = 0;
    int end = 0;

    for (int i = 0; i < n; i++) {
        cin >> lesson[i];
        end += lesson[i];
    }

    int result = 1000000000;

    while(start <= end) {
        int mid = (start + end) / 2;
        if (cal(mid)) {
            result = min(result, mid);
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    cout << result;
}