#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


int n, m, k;
int a[11][11];
int ground[11][11];
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
stack<int> tree[11][11];
queue<int> deadTree[11][11];
queue<pair<int,int>> addTree;
int cnt;

// 4 3 2 1

// 1 2
// 3 4


void spring() {

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            vector<int> tmp;

            while(!tree[i][j].empty()) {
                int year = tree[i][j].top();
                tree[i][j].pop();

                if (ground[i][j] >= year) {
                    ground[i][j] -= year;
                    year++;
                    tmp.push_back(year);
                    if(year % 5 == 0) {
                        addTree.push({i, j});
                    }
                }     
                else {
                    deadTree[i][j].push(year);
                    cnt--;
                }
            }

            while(!tmp.empty()) {
                tree[i][j].push(tmp.back());
                tmp.pop_back();
            }
        }


    }
}

void summer() {

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            while(!deadTree[i][j].empty()) {
                int year = deadTree[i][j].front();
                deadTree[i][j].pop();
                ground[i][j] += (year / 2);
            }
        }
    }

}

void autumn() {

    while(!addTree.empty()) {

        int r = addTree.front().first;
        int c = addTree.front().second;
        addTree.pop();

        for (int i = 0; i < 8; i++) {
            int y = r + dy[i];
            int x = c + dx[i];
            if(y > n || x > n || y <= 0 || x <= 0)
                continue;
            tree[y][x].push(1);
            cnt++;
        }
    }

}

void winter() {

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ground[i][j] += a[i][j];
        }
    }
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }   
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ground[i][j] = 5;
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        tree[x][y].push(z);
        cnt++;
    }

    for (int i = 0; i < k; i++) {
        spring();
        summer();
        autumn();
        winter();
    }


    cout << cnt;
}