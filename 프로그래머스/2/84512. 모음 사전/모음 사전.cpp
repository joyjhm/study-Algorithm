#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt = 0;
int result = 0;
vector<char> vowels = {'A', 'E', 'I', 'O', 'U'};
vector<char> v;

void brute_force(string word) {

    if(v.size() > 5) {
        return;
    }
    
    if(string(v.begin(), v.end()) == word) {
        result = cnt;
        return;
    }
    
    cnt++;
    
        
    for (int i = 0; i < 5; i++) {
        
        v.push_back(vowels[i]);
        brute_force(word);
        v.pop_back();
    }
}


int solution(string word) {
    int answer = 0;
    brute_force(word);
    answer = result;
    return answer;
}