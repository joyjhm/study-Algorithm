#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int,int> m1, pair<int,int> m2) {
    return m1.second > m2.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int,int> m;
    
    for (int i = 0; i < tangerine.size(); i++) {
        m[tangerine[i]]++;
    }
    vector<pair<int, int>> v(m.begin(), m.end());

    sort(v.begin(), v.end(), compare);
    
    for (int i = 0; i < v.size(); i++) {
        k = k - v[i].second;
        if(k <= 0) {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}