#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string toBinary(int cnt) {
    string str = "";
    
    while(cnt > 0) {
        if(cnt % 2 == 1) {
            str += '1';
        } else {
            str += '0';
        }
        cnt = cnt / 2;
    }
    
    reverse(str.begin(), str.end());
    
    return str;
}

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int remove_zero = 0;
    
    while(s != "1") {
        // 1번
        int zero_cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if(s[i] == '0') {
                zero_cnt++;
            }
        }
        
        // 2번
        int one_cnt = s.length() - zero_cnt;
        s = toBinary(one_cnt);
        
        remove_zero += zero_cnt;
        cnt++;
        cout << s;
    }
    
    answer.push_back(cnt);
    answer.push_back(remove_zero);
    
    return answer;
}