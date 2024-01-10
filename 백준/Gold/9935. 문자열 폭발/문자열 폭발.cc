#include<iostream>
#include<stack>
#include<algorithm>
#include<string>

using namespace std;

stack<pair<char, int>> word;
stack<char> answer;
string explosion;


int main() {
    string str;
    cin >> str;
    cin >> explosion;
    int idx = 0;
    int len = explosion.length();
    for(int i = 0; i < str.length(); i++) {
        if(word.empty()) {
            idx = 0;
        } else {
            idx = word.top().second;
        }
        if(str[i] == explosion[idx]) {
            idx++;
        }
        else {
            idx = 0;
            if(str[i] == explosion[idx]){
                idx++;
            }
        }
        word.push({str[i], idx});

        if (word.top().second == len) {
            for (int j = 0; j < len; j++) {
                word.pop();
            }
        }
    }

    while(!word.empty()) {
        answer.push(word.top().first);
        word.pop();
    }

    if(answer.empty()) {
        cout << "FRULA";
    }
    else {
        while(!answer.empty()) {
            cout << answer.top();
            answer.pop();
        }        
    }



}