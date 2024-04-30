#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[50];
vector<int> v;
bool visited[50];
int leaf = 0;
int n, k;

void dfs(int i) {

    if (i == -1) {
        if(v.back() == k) {
            for (int i= 0; i < v.size(); i++) {
                visited[v[i]] = true;
            }
            return;
        }

        for (int i = 1; i < v.size(); i++) {
            visited[v[i]] = true;
        }
        return;
    }

    v.push_back(i);
    dfs(parent[i]);
    v.pop_back();
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> parent[i];
    }
    cin >> k;

    parent[k] = -1;

    for (int i = 0; i < n; i++) {
        dfs(i);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if(!visited[i]) {
            cnt++;
        }
    }
    
    cout << cnt;
}

