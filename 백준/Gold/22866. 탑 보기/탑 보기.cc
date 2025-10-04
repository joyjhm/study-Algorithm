#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
#define L 100000
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    vector<int> result(n + 1);
    vector<int> near(n + 1, 100001);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];

    }

    stack<int> s;

    for (int i = 1; i <= n; i++) {
        while(!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        result[i] = s.size();
        if(!s.empty()) {
            near[i] = s.top();
        }
        s.push(i);
    }

    s = {};
    for (int i = n; i >= 1; i--) {
        while(!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        result[i] += s.size();
        int cnt = s.size();
        if(!s.empty() && abs(near[i] - i) > abs(s.top() - i)) {
            near[i] = s.top();
        }
        s.push(i);
    }   

    for (int i = 1; i <= n; i++) {
        if(result[i] != 0) {
            cout << result[i] << " " << near[i] << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }

}