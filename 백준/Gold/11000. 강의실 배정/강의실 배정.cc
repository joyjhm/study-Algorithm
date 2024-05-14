#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> &p1, pair<int,int> &p2) {

    if (p1.first == p2.first) {
        return p1.second < p2.second;

    }
    return p1.first < p2.first;
    
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    // priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[i].first = a;
        v[i].second = b;
    }

    sort(v.begin(), v.end(), compare);
    priority_queue<int, vector<int>, greater<int>> pq;

    int result = 0;
    pq.push(-1);
    for (int i = 0; i < n; i++) {
        int start = v[i].first;
        int dest = v[i].second;
        bool isPossible = true;
        int p = pq.top();

        if(p <= start) {
            pq.pop();
        }
        pq.push(dest);
        

    }

    cout << pq.size();
    
}