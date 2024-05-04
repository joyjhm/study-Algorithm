#include<iostream>
#include<string>
#include<stack>

using namespace std;

stack<char> alpha;
stack<pair<int,char>> op;
stack<pair<int,char>> tmp;

int main() {
    string str;
    cin >> str;

    int cnt = 0;
    for (int i = 0; i < str.length(); i++) {
        if(str[i] >= 65 && str[i] <= 90) {
            cout << str[i];
        }
        else {
            int p;
            if(str[i] == '+' || str[i] == '-') {
                p = 0;
            } 
            else if(str[i] == '*' || str[i] == '/') {
                p = 1;
            }
            else if(str[i] == '(') {
                p = 2;
            }

            if(str[i] == '(') {
                op.push({p, str[i]});
                cnt++;
            }
            else if(op.empty()) {
                op.push({p, str[i]});
  
            } 
            else {
                if(str[i] == ')') {
                    while(op.top().second != '(') {
                        cout << op.top().second;
                        op.pop();
                    }
                    op.pop();
                    cnt--;
                }
                else if(cnt > 0) {

                    while(op.top().second != '(' && op.top().first >= p) {
                        cout << op.top().second;
                        op.pop();
                    }
                    op.push({p, str[i]});
                }

                else if(op.top().first < p) {
                    op.push({p, str[i]});
                }
                else {
                    while(!op.empty() && op.top().first >= p) {
                        cout << op.top().second;
                        op.pop();
                    }
                    op.push({p, str[i]});
                }
            }
        }
    }

    while(!op.empty()) {
        cout << op.top().second;
        op.pop();
    }
}

