#include <iostream>
#include <stack>
using namespace std;

int arr[1000001];
int answer[1000001];
stack<pair<int,int>> s;
int main() {
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }


    for (int i = 1; i<= n; i++) {
        while (!s.empty() && s.top().first < arr[i]) {
            int idx = s.top().second;
            answer[idx] = arr[i];
            s.pop();
        }
        s.push({arr[i], i});

    }

    while(!s.empty()) {
        int idx = s.top().second;
        answer[idx] = -1;
        s.pop();
    }

    for (int i = 1; i <=n; i++) {
        cout << answer[i] << " ";
    }

}