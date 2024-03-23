#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    map<int,int> m;
    map<int,int>::iterator iter;
    
    for (string op : operations) {
        char c = op[0];
        int num = stoi(op.substr(2));

        if (c == 'D') {
            if(m.empty()) {
                continue;
            }
            
            if (num == 1) {
                iter = --m.end();

            } else {
                iter = m.begin();  
            }
            
            int key = iter->first;
            m[key]--;
            if(m[key] == 0) {
                m.erase(iter->first);
            }
            
        }
        else if (c == 'I') {
            m[num]++;
        } 
    }
    
    if(m.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        iter = --m.end();
        answer.push_back(iter->first);
        iter = m.begin();
        answer.push_back(iter->first);
    }
    
    return answer;
}