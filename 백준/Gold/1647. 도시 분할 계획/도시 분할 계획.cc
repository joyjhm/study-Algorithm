#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int parent[100001];

struct Line {

    int n1;
    int n2;
    int cost;

};

struct compare {

    bool operator()(Line l1, Line l2) {

        return l1.cost > l2.cost;
    }
};



priority_queue<Line, vector<Line>, compare> pq;

int find(int x) {

    if(x != parent[x]) {
        return parent[x] = find(parent[x]);
    }

    return parent[x];
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);

    if (x < y) {
        parent[y] = x;
    } else {
        parent[x] = y;
    }
}

int kruskal() {

    int total_cost = 0;
    int max_cost = 0;

    while(!pq.empty()) {
        int n1 = pq.top().n1;
        int n2 = pq.top().n2;
        int cost = pq.top().cost;
        pq.pop();

        if(find(n1) != find(n2)) {
            uni(n1, n2);
            total_cost += cost;
            max_cost =  max(cost, max_cost);
        }
    }

    return total_cost - max_cost;
}



int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int n1, n2, cost;
        cin >> n1 >> n2 >> cost;
        pq.push({n1, n2, cost});

    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int result = kruskal();

    cout << result;

}