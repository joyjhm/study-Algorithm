#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int result = 100;
int cnt = 0;

vector<pair<int, int>> pole;
vector<int> v;
int n;



bool compare(pair<int,int> p1, pair<int,int> p2) {
    
    if(p1 == p2) {
        return p1.second < p2.second;
    } else {
        return p1.first < p2.first;
    }
}

void dfs(int idx,  int cnt) {

    if(result < cnt) {
        return;
    }

    if(idx == n) {
        result = min(result, cnt);
        return;
    }

    if(v.empty() || v.back() < pole[idx].second) {
        v.push_back(pole[idx].second);
        dfs(idx + 1, cnt);
        v.pop_back();
    }

    dfs(idx + 1, cnt + 1);

}

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pole.push_back({a,b});
    }

    sort(pole.begin(), pole.end(), compare);
    dfs(0, 0);

    cout << result;
}