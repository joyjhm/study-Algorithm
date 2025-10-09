#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int n = gems.size();

    map<string, int> m;
    map<string, bool> type;

    for (int i = 0; i < n; i++) {
        type[gems[i]] = true;
    }

    int cnt = type.size();

    int target_s = 0;
    int target_e = n - 1;

    int start = 0;

    

    for (int end = 0; end < n; end++) {
        m[gems[end]]++;

        if((int)m.size() == cnt) {
            while(m[gems[start]] - 1 != 0) {
                m[gems[start]]--;
                start++;
            }
                    
            if(target_e - target_s > end - start) {
                target_s = start;
                target_e = end;
            }
        }
    }

    return {target_s + 1, target_e + 1};
}