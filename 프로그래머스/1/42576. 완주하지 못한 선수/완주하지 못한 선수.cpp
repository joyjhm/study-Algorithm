#include <string>
#include <vector>
#include <map>
using namespace std;


map<string, int> m;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for (int i = 0; i < completion.size(); i++) {
        string target = completion[i];
        m[target]++;        
    }
    
    for (int i = 0; i < participant.size(); i++) {
        string target = participant[i];
        if(m[target] == 0) {
            answer = target;
        } else {
            m[target]--;
        }
    }
    
    return answer;
}