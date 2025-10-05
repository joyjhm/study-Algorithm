#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int transfer(int month, int day) {
    return month * 100 + day;
}


bool compare(pair<int,int> p1, pair<int,int> p2) {
    if(p1.first == p2.first) {
        return p2.second < p1.second;
    }
    return p1.first < p2.first;
}

// 3월 1일, 12월 1일

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> v;

    for (int i = 0; i < n; i++) {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        int start = transfer(sm, sd);
        int end = transfer(em, ed);
        v.push_back({start, end});
    }

    sort(v.begin(), v.end(), compare);

    int target_start = 301;
    int target_end = 1201;
    int cur = target_start;
    int idx = 0;

    int result = 0;
    while(cur < target_end) {
        int best = cur;
        while(idx < n && v[idx].first <= cur) {
            best = max(v[idx].second, best);
            idx++;
        }

        if(cur == best) {
            cout << 0;
            return 0;
        }

        cur = best;
        result++;
    }

    cout << result;

}