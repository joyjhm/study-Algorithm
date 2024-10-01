#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, int> m;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    
    
    for (int i = 0; i < phone_book.size(); i++) {
        m[phone_book[i]] = i + 1;
    }
    
    for (int i = 0; i < phone_book.size(); i++) {
        string target = phone_book[i];
        string str = "";
        
        for (int j = 0; j < target.length(); j++) {
            str += target[j];
            if(m[str] && m[str] != i + 1) {
                return false;   
            }
        }
    
    }
    
    
    
    return answer;
}