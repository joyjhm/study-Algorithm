#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int arr[1000001];
int cnt[1000001];
int result[1000001];
stack<int> s; 



int main() {
    int n;
    cin >> n;


    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;        
    }

    for (int i = 0; i < n; i++) {
        while(!s.empty() && cnt[arr[s.top()]] < cnt[arr[i]]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < n; i++) {
        if(result[i] == 0) {
            result[i] = -1;
        }
        cout << result[i] << " ";
    }

}