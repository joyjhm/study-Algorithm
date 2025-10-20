#include <string>
#include <vector>
#include <stack>
#include <map>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

char op[3] = {'+', '-', '*'};
map<char, int> m;
bool visited[3];
long long answer;

long long calculate(long long num1, long long num2, char oper) {
    
    if(oper == '+') {
        return num1 + num2;
    }
    else if(oper == '-') {
        return num1 - num2;
    }
    else {
        return num1 * num2;
    }
}

long long relate(string expression) {
    int len = expression.length();

    string str = "";
    stack<long long> nums;
    stack<char> s;

    for (int i = 0; i < len; i++) {
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            char oper = expression[i];
            nums.push(stoll(str));
            while(!s.empty() && m[s.top()] >= m[oper]) {
                long long num1 = nums.top();
                nums.pop();
                long long num2 = nums.top(); 
                nums.pop();
                long long val = calculate(num2, num1, s.top());
                nums.push(val);
                s.pop();                
            }
            s.push(oper);  
            str = "";  
        }   
        else {
            str += expression[i];
        }
    }
    nums.push(stoll(str));

    while(!s.empty()) {
        long long num1 = nums.top();
        nums.pop();
        long long num2 = nums.top();
        nums.pop();
        long long val = calculate(num2, num1, s.top());
        s.pop();
        nums.push(val);
    }
    return nums.top();
}

void dfs(int cnt, string expression) {
    
    if (cnt == 3) {
        long long val = relate(expression);
        answer = max(answer, llabs(val));
        return;
    }

    for (int i = 0; i < 3; i++) {
        if(!visited[i]) {
            visited[i] = true;
            m[op[i]] = cnt + 1;
            dfs(cnt + 1, expression);
            visited[i] = false;
            m[op[i]] = 0;
        }
    }
}


long long solution(string expression) {

    dfs(0, expression);

    return answer;
}