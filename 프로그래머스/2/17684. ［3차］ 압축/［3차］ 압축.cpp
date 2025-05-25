#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    map<string, int> m;
    
    for (int i = 0; i < 26; i++) {
        string s(1, 'A' + i);
        m[s] = i + 1;
    }
    int len = 27;
    int i;
    for (i = 0; i < msg.length(); i++) {
        int idx = i;
        string str(1, msg[i]);
        string dic(1, msg[i]);
        for (int j = i + 1; j < msg.length(); j++) {
            if(m.count(str + msg[j])) {
                str += msg[j];
                dic += msg[j];
                idx++;
            }
            else {
                dic += msg[j];
                break;
            }
        }
                
        i = idx;
        answer.push_back(m[str]);
        
        m[dic] = len; 
        len++;

        
    }
    
    
    return answer;
}