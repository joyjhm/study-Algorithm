#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,m;
int arr[8];
int visited[10000];
vector<int> v;
int idx = 0;
void dfs(int depth) {

    if(depth == m) {
        for(int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << '\n';
    }
    else {
        for (int i = 0; i < idx; i++) {
            if (visited[arr[i]]) {
                visited[arr[i]] -= 1;
                v.push_back(arr[i]);
                dfs(depth + 1);
                visited[arr[i]] += 1;
                v.pop_back();
            }
        }
    }
}

int main() {

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if(!visited[temp]) {
            arr[idx] = temp;
            idx++;
        } 
            visited[temp]++;
    }

    sort(arr, arr + idx);
    dfs(0);

}