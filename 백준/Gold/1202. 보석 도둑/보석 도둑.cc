#include <iostream>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[300000];
multiset<int> bag;
int n, k;

struct compare {

    bool operator()(pair<int,int> p1, pair<int,int> p2) {
        if(p1.second == p2.second) {
            return p1.first > p2.first;
        }
        return p1.second < p2.second;
    }
};

int main() {

    cin >> n >> k;
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;


    for (int i = 0; i < n; i++) {
        int m, v;
        cin >> m >> v;

        pq.push({m, v});
    }


    for (int i = 0; i < k; i++) {
        int tmp;
        cin >> tmp;
        bag.insert(tmp);
    }

    long long result = 0;

    while(!pq.empty()) {
        int m = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        auto it = bag.lower_bound(m);
        if(it == bag.end()) {
            continue;
        }

        result += v;
        bag.erase(it);

    }

    cout << result;


}