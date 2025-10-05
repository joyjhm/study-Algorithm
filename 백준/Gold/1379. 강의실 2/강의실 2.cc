#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Lesson {
    int start;
    int end;
    int idx;
};

int main() {

    int n;
    cin >> n;

    vector<Lesson> v(n);
    vector<int> result(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> v[i].idx >> v[i].start >> v[i].end;
    }

    sort(v.begin(), v.end(), [](auto& p1, auto& p2) {
    if(p1.start == p2.start) {
        return p2.end < p1.end;
    }
    return p1.start < p2.start;
    });

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    priority_queue<int, vector<int>, greater<int>> room;

    int num = 0;
    int cnt = 1;

    for (int i = 1; i <= n; i++) {
        room.push(i);
    }

    for (auto [start, end, idx]: v) {
        
        while(!pq.empty() && pq.top().first <= start) {
            room.push(pq.top().second);
            pq.pop();
        }

        int room_idx = room.top();

        pq.push({end, room_idx});
        room.pop();

        result[idx] = room_idx;
        num = max(num, (int) pq.size());
        
    }

    cout << num << '\n';
    for (int i = 1; i <= n; i++) {
        cout << result[i] << '\n';
    }

}