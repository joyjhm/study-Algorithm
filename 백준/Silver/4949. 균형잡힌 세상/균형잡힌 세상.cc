#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    
    while(true) {
        getline(cin, str, '.');
        if(str == "\n") {
            break;
        }
        stack<char> s;
        bool isTrue = true;
        for (int i = 0; i < str.length(); i++) {
            if(str[i] == '(') {
                s.push(str[i]);
            } 
            else if(str[i] == '[') {
                s.push(str[i]);
            }
            else if(str[i] == ')') {
                if(s.empty() || s.top() != '(') {
                    isTrue = false;
                    break;
                }
                else {
                    s.pop();
                }
            } 
            else if (str[i] == ']') {
                if(s.empty() || s.top() != '[') {
                    isTrue = false;
                    break;
                }
                else {
                    s.pop();
                }
            }
        }

        if(!s.empty()) {
            isTrue = false;
        }

        if(isTrue) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }

}