#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
int arr[8];
bool num[10000];
int idx = 0;
vector<int> v;

void dfs(int depth, int start) {

    if (depth == m) {
        for(int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = start; i < idx; i++) {
        v.push_back(arr[i]);
        dfs(depth + 1, i);
        v.pop_back();
    }

}

int main() {

    cin >> n >> m;
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(!num[temp]) {
            num[temp] = true;
            arr[idx] = temp;
            idx++;
        }
    }
    sort(arr, arr + idx);
    dfs(0, 0);

}