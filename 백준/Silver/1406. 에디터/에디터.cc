#include <iostream>
#include <string> 
#include <stack>

using namespace std;

int main() {
    string s;
    cin >> s;
    int m;
    cin >> m;

    stack<char> left;
    stack<char> right;

    for (int i = 0; i < s.length(); i++) {
        left.push(s[i]);
    }

    for (int i = 0; i < m; i++) {
        char command;
        cin >> command;

        if(command == 'L') {
            if(!left.empty()) {
                char c = left.top();
                left.pop();
                right.push(c);
            }
        }
        else if (command == 'D') {
            if(!right.empty()) {
                char c = right.top();
                right.pop();
                left.push(c);
            }
        }
        else if (command == 'B') {
            if(!left.empty()) {
                left.pop();
            }
        }
        else {
            char alp;
            cin >> alp;
            left.push(alp);
        }
    }
    while(!left.empty()) {
        char c = left.top();
        left.pop();
        right.push(c);
    }

    while(!right.empty()) {
        char c = right.top();
        right.pop();
        cout << c;
    }
}