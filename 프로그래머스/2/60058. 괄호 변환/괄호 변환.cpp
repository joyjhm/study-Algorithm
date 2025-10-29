#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool check(string str) {
    
    stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            s.push('(');
        }
        else {
            if(s.empty()) {
                return false;
            }
            s.pop();
        }
    }

    if(!s.empty()) {
        return false;
    }

    return true;
}

string convert(string w) {
    
    if(w == "") {
        return "";
    }    
    
    int left = 0;
    int right = 0;
    int idx = 0;

    for (idx = 0; idx < w.length(); idx++) {
        if(w[idx] == '(') {
            left++;
        }
        else {
            right++;
        }
        
        if(left == right) {
            break;
        }
    }
    string u = w.substr(0, idx + 1);
    string v = w.substr(idx + 1);


    if(check(u)) {
        return u + convert(v);
    }
    else {
        string tmp = "";
        for (int i = 1; i < u.length() - 1; i++) {
            if(u[i] == '(') {
                tmp += ")";
            }
            else {
                tmp += "(";
            }
        }
        return "(" + convert(v) + ")" + tmp;
    }

}

string solution(string p) {
    string answer = convert(p);    

    return answer;
}