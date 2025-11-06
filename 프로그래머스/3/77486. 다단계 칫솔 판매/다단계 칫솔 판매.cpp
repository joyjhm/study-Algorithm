#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {

    int n = enroll.size();
    vector<int> answer(n);

    map<string, pair<string, int>> parent;
    
    for (int i = 0; i < n; i++) {
        if(referral[i] == "-") {
            parent[enroll[i]] = {"center", i};
        }
        else {
            parent[enroll[i]] = {referral[i], i};
        }
    }
    
    int m = seller.size();
    

    for (int i = 0; i < m; i++) {
        int price = amount[i] * 100;
        string cur = seller[i];
        while(cur != "center" && price != 0) {
            int rest = price / 10;
            auto [p, idx] = parent[cur];
            if(idx == -1) {
                break;
            }
            answer[idx] += price - rest;
            price = rest;
            cur = p;
        }
    }
    
    return answer;
}