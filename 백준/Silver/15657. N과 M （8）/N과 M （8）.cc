#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v;
int num[8];
bool visited[8];


void dfs(int depth, int idx) {

    if(depth == m) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = idx; i < n; i++) {
        if(!v.empty()) {
            if(v.back() > num[i]) {
                continue;
            }
        }
        v.push_back(num[i]);
        dfs(depth + 1, idx);
        v.pop_back();
    }

}

int main() {

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    dfs(0, 0);
}