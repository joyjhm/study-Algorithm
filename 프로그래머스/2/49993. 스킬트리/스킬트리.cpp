#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int len = skill_trees.size();
    
    vector<int> order(26, -1);
    
    for (int i = 0; i < skill.length(); i++) {
        order[skill[i] - 'A'] = i;
    }
    
    for (int i = 0; i < len; i++) {
        vector<bool> target(26);
        vector<int> visited(skill.length());
        string str = skill_trees[i];
        
        int idx = 0;
        bool isPossible = true;
        for (int j = 0; j < str.length(); j++) {
            if(order[str[j] - 'A'] == -1) {
                continue;
            }
            else if(order[str[j] - 'A'] == idx) {
                idx++;   
            }
            else {
                isPossible = false;
                break;
            }
        }
        
        if(isPossible) {
            answer++;
        }
    }
    
    return answer;
}