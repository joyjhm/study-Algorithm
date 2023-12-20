#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

struct Chicken {
    int row;
    int col;
    bool visited;
    Chicken(int i, int j) {
        row = i;
        col = j;
        visited = false;
    }

};

struct House {
    int row;
    int col;

    House(int i, int j) {
        row = i;
        col = j;
    }
};


int n, m;
vector<Chicken> chicken;
vector<House> house;
vector<Chicken> pick;
int result = 100000;


int sumDistance() {
    int allDistance = 0;
    for(int i = 0; i < house.size(); i++) {
        int minDistance = 999999;
        for(int j = 0; j < pick.size(); j++) {
            minDistance = min(minDistance, abs(house[i].row - pick[j].row) + abs(house[i].col - pick[j].col));
        }
        allDistance += minDistance;

    }

    return allDistance;
}   


void dfs(int cnt, int start) {
    if(cnt == m) {
        result = min(result,sumDistance());
        return;
    }

    for(int i = start; i < chicken.size(); i++) {
        if(!chicken[i].visited) {
            chicken[i].visited = true;
            pick.push_back(chicken[i]);
            dfs(cnt + 1, i + 1);
            chicken[i].visited = false;
            pick.pop_back();
        }

    }
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int num;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> num;
            if(num == 2) {
                chicken.push_back(Chicken(i,j));

            }
            if(num == 1) {
                house.push_back(House(i,j));
            }
        }
    }
    dfs(0, 0);
    cout << result;
}