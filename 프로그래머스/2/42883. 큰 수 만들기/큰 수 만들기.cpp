#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int n = number.length();    

    priority_queue<pair<char,int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
    vector<int> v;
    int cnt = 0;
    for (int i = 0; i < n; i++) {

        while (!pq.empty() && pq.top().first < number[i]  && cnt < k) {
            v.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }
        pq.push({number[i], i});
    }
    
    while(v.size() != k) {
        v.push_back(pq.top().second);
        pq.pop();
    }

    sort(v.begin(), v.end());

    int idx = 0;
    for (int i = 0; i < n; i++) {
        if(idx < k && v[idx] == i) {
            idx++;
        }
        else {
            answer += number[i];
        }
    }
    
    return answer;
}