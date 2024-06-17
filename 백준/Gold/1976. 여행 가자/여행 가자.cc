#include <iostream>
#include <vector>

using namespace std;


vector<int> v[201];
vector<int> path;

int n, m;


bool visited[201];
int cur;

void dfs(int cur) {


    for (int i = 0; i < v[cur].size(); i++) {
        int next = v[cur][i];
        if(!visited[next]) {
            visited[next] = true;
            dfs(next);
        }
    }

}

int main() {

    cin >> n;
    cin >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int check;
            cin >> check;
            if(check == 1) {
                v[i].push_back(j);
            }            
        }

    }

    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        path.push_back(tmp);
    }

    bool result = true;

    visited[path[0]] = true;
    dfs(path[0]);
    
    for (int i = 0; i < m; i++) {
        if(!visited[path[i]]) {
            result = false;
            break;
        }
    }

    if(result) {
        cout << "YES";
    } else {
        cout << "NO";
    }

}