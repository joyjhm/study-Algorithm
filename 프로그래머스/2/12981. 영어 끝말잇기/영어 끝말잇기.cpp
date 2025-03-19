#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    map<string,int> m;    
    m[words[0]]++;
    int idx = 2;
    int cnt = 1;
    char start = words[0][words[0].length() - 1];
    for (int i = 1; i < words.size(); i++) {
        if(idx > n) {
            idx = 1;
            cnt++;
        }
        if(words[i][0] != start) {
            answer[0] = idx;
            answer[1] = cnt;
            break;
        }
        if (m[words[i]] > 0) {
            answer[0] = idx;
            answer[1] = cnt;
            break;
        }
        start = words[i][words[i].length() - 1];
        m[words[i]]++;
        idx++;
    }
    
    return answer;
}