#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000001
using namespace std;

struct Line {
    int start;
    int dest;
    int cost;
};

int v, e;
vector<Line> line;
int parent[10001];
int result = 0;

bool compare(Line l1, Line l2) {

    return l1.cost < l2.cost;
}

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    else {
        return parent[x] = find(parent[x]);
    }
    
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
}

bool isSameparent(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return true;
    }
    else {
        return false;
    }
}


int main() {

    cin >> v >> e;
        
    for (int i = 0; i < e; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        line.push_back({a,b,c});
    }

    sort(line.begin(), line.end(), compare);

    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < line.size(); i++) {
        if(!isSameparent(line[i].start, line[i].dest)) {
            uni(line[i].start, line[i].dest);
            result += line[i].cost;
        }
    }

    cout << result;
}