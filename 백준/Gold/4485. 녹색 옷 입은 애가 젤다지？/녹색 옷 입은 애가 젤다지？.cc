#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

struct Point {
    int cost;
    int y;
    int x;
};

struct compare {

    bool operator()(Point& p1, Point& p2) {
        if(p1.cost == p2.cost) {
            if(p1.y == p2.y) {
                return p1.x > p2.x;
            }
            return p1.y > p2.y;
        }
        return p1.cost > p2.cost;
    }
};

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int dijkstra(vector<vector<int>>& arr, int n) {
    
    priority_queue<Point, vector<Point>, compare> pq;
    vector<vector<int>> distance(n, vector<int>(n, INF));
    pq.push({arr[0][0], 0, 0});
    distance[0][0] = arr[0][0];

    while(!pq.empty()) {
        int cost = pq.top().cost;
        int y = pq.top().y;
        int x = pq.top().x;
        pq.pop();

        if(cost > distance[y][x]) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int ty = y + dy[i];
            int tx = x + dx[i];

            if (ty >= n || ty < 0 || tx >= n || tx < 0) 
                continue;

            if(distance[ty][tx] > cost + arr[ty][tx]) {
                distance[ty][tx] = cost + arr[ty][tx];
                pq.push({cost + arr[ty][tx], ty, tx});
            }
        }
    }

    return distance[n - 1][n - 1];
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int idx = 1;
    while(true) {    
        cin >> n;

        if(n == 0) {
            break;
        }

        vector<vector<int>> arr(n, vector<int>(n));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }

        int value = dijkstra(arr, n);

        cout << "Problem " << idx << ": " << value << '\n';
        idx++;
    }
}