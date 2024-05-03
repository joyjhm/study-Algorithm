#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

int main() {

    string str;
    cin >> str;

    int result = 0;
    stack<char> s;
    int tmp = 1;
    char prv = ' ';
    for (int i = 0; i < str.length(); i++) {

        if(str[i] == '(') {
            tmp *= 2;
            s.push(str[i]);
        } else if (str[i] == '[') {
            tmp *= 3;
            s.push(str[i]);
        } else {
            if(str[i] == ')') {

                if(s.empty() || s.top() == '[') {
                    result = 0;
                    break;
                }
                s.pop();

                if(prv == '(') {
                    result += tmp;
                    tmp /= 2;
                } else {
                    tmp /= 2;
                }
            }
            else if(str[i] == ']') {

                if(s.empty() || s.top() == '(') {
                    result = 0;
                    break;
                }
                s.pop();

                if(prv == '[') {
                    result += tmp;
                    tmp /= 3;
                } else {
                    tmp /= 3;
                }
            }
        } 
        prv = str[i];
    }

    if(!s.empty()) {
        result = 0;
    }

    cout << result;
}
