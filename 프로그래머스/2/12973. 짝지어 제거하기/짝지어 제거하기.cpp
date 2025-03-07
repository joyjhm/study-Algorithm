#include<stack>
#include<string>
using namespace std;

stack<char> s;

int solution(string str) {
    
    for (int i = 0; i < str.length(); i++) {
        if(s.empty()) {
            s.push(str[i]);
        }
        else if(s.top() == str[i]) {
            s.pop();
        }
        else {
            s.push(str[i]);
        }
    }

    if(s.empty()) {
        return 1;
    }
    else {
        return 0;
    }
}