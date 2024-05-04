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


    for (int i = 0; i < str.length(); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            cout << str[i];
        }
        else if(str[i] == '(') {
            op.push({0, str[i]});
        }
        else if(str[i] == ')') {
            if(str[i] == ')') {
                while(op.top().second != '(') {
                    cout << op.top().second;
                    op.pop();
                }
                op.pop();
            }
        }
        else {
            int p;
            if(str[i] == '+' || str[i] == '-') {
                p = 1;
            } 
            else if(str[i] == '*' || str[i] == '/') {
                p = 2;
            }

            while(!op.empty() && op.top().first >= p) {
                cout << op.top().second;
                op.pop();
            }
            op.push({p, str[i]});


        }
    }

    while(!op.empty()) {
        cout << op.top().second;
        op.pop();
    }
}

