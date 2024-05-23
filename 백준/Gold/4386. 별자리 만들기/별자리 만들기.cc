#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct Line {
    int start;
    int dest;
    float distance;
};

struct compare {

    bool operator() (Line& l1, Line& l2) {
        return l2.distance < l1.distance;
    }
};

int n;
vector<pair<float, float>> star(100);
bool visited[100];
int parent[100];

priority_queue<Line, vector<Line>, compare> pq;
float result = 0;


int find(int x) {
    if(x == parent[x]) {
        return x;
    }
    else {
        return find(parent[x]);
    }

}

bool uni(int x, int y) {

    x = find(x);
    y = find(y);
    if (x == y) {
        return false;
    }

    else {
        parent[y] = x;
        return true;
    }

}




void mst() {

    while(!pq.empty()) {
        int start = pq.top().start;
        int dest = pq.top().dest;
        float distance = pq.top().distance;
        pq.pop();

        if (!uni(start, dest)) {
            continue;

        }
        result += distance;
    }

}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> star[i].first >> star[i].second;
        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            float tmp = pow((star[i].first - star[j].first), 2.0) + pow((star[i].second - star[j].second), 2.0);
            float cost = sqrt(tmp);
            pq.push({i, j, cost});  
        }
    }

    mst();
    result = round(result * 100) / 100;
    cout << result;
}
