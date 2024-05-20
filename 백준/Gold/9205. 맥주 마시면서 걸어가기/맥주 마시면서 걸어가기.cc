#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int n, house_x, house_y, con_x, con_y, fest_x, fest_y;
vector<pair<int,int>> con;
bool isPossible;
bool visited[100];

bool check(int cur_x, int cur_y, int target_x, int target_y) {

    if(abs(cur_x - target_x) + abs(cur_y - target_y) <= 1000) {
        return true;
    }
    return false;
}

void dfs(int cur_x, int cur_y) {
    
    if(isPossible) {
        return;
    }

    if (check(cur_x,cur_y, fest_x, fest_y)) {
        isPossible = true;
        return;
    }

    for (int i = 0; i < n; i++) {
        if(!visited[i] && check(cur_x, cur_y, con[i].first, con[i].second)) {
            visited[i] = true;
            dfs(con[i].first, con[i].second);

        }
    }

}

int main() {

    int t;
    cin >> t;
    while(t--) {
        int beer = 20;
        cin >> n;
        cin >> house_x >> house_y;
        for (int i = 0; i < n; i++) {
            cin >> con_x >> con_y;
            con.push_back({con_x, con_y});

        }
        cin >> fest_x >> fest_y;

        isPossible = false;
        dfs(house_x, house_y);


        if (isPossible) {
            cout << "happy" << '\n';
        } else {
            cout << "sad" << '\n';
        }

        con.clear();
        memset(visited, false, sizeof(visited));
    }
}