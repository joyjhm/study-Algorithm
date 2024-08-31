#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

stack<char> s;


int main() {

    int n, k;
    string str;
    cin >> n >> k;
    cin >> str;

    int len = n - k;


    for (int i = 0; i < str.length(); i++) {
        while(!s.empty() && s.top() < str[i] && s.size() + str.length() - i > len) {
            s.pop();
        }
        s.push(str[i]);
    }

    while(s.size() != len) {
        s.pop();
    }

    vector<char> result;

    while(!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }

    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }

}