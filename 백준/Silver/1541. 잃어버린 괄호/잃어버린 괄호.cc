/*
    다른 표현 방법
    파싱하지 않고 string의 index로 접근
*/

#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

vector<int> sum;

vector<string> split(string str, char deli) {
    istringstream iss(str);
    string buffer;

    vector<string> result;
    while (getline(iss, buffer, deli)) {
        result.push_back(buffer);               
    }
    return result;
}

int main() {
    string s;
    cin >> s;
    vector<string> minus = split(s, '-');    // - 연산자로 파싱
    for (int i=0; i < minus.size();i++){
        vector<string> plus = split(minus[i], '+'); // - 연산자 사이에 + 연산자들로 이루어진 vector를 만든다.
        int add = 0;
        for (int j = 0; j < plus.size(); j++) {
            add += stoi(plus[j]);    // add: + 연산자로 이루어진 값들을 더한다.
        }
        sum.push_back(add);

    }
    int result = sum[0];            // 처음 마이너스 만나기 전까지의 덧셈의 합은 더함.
    for(int i =1; i < sum.size(); i++) {
        result -= sum[i];        //  그 이후에 - 만나면 덧셈의 합들을 빼준다.
    }

    cout << result;
}
