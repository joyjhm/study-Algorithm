#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool isFirst = true;
    
    for (int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') {
            answer += s[i];
            isFirst = true;            
        }
        else {
            if(isFirst && s[i] >= 'a' && s[i] <= 'z') {
                answer += toupper(s[i]);
            }
            else if (!isFirst && s[i] >= 'A' && s[i] <= 'Z') {
                answer += tolower(s[i]);
            }
            else {
                answer += s[i];
            }
            isFirst = false;
        }
    
    }
    
    return answer;
}