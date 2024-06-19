#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct compare {

    bool operator()(pair<int,int> p1, pair<int,int> p2) {
        
        if (p1.first == p2.first) {
            return p1.second > p2.second;
        }
        return p1.first < p2.first;
    }

};

int n;

int a[101];
int b[101];

int main() {
    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int,int>>, compare> pq;
    vector<int> v[101];


    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pq.push({a[i], i});
    }

    int m;
    cin >> m;

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        v[b[i]].push_back(i);
    }

    int point_a = 0;
    int point_b = 0;

    vector<int> result;

    while(!pq.empty()) {
        int cur = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        if(idx > point_a) {
    
            for (int i = 0; i < v[cur].size(); i++) {
                if(point_b < v[cur][i]) {
                    point_b = v[cur][i];
                    point_a = idx;
                    result.push_back(cur);
                    break;
                }
            }

        }

    }

    int s = result.size();

    cout << s << '\n';

    for (int i = 0; i < s; i++) {
        cout << result[i] << " ";
    }

}