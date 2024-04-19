#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    int result = 0;
    while(pq.size() > 1) {

        int add_val = 0;
        for (int i = 0; i < 2; i++) {
            add_val += pq.top();
            pq.pop();
        }

        result += add_val;
        pq.push(add_val);
    }

    cout << result;
}