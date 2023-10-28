#include<iostream>
#include<stack>
using namespace std;
int n;
int grape[100][100];
bool visited[100][100];
stack<int> s;

void dfs(int x) {
    int node = s.top();
    for(int i = 0; i < n; i++) {
        if(grape[node][i] == 1 && !visited[x][i]) {
            visited[x][i] = true;
            s.push(i);
            grape[x][i] = 1;
            dfs(x);
            s.pop();
        }
    } 
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grape[i][j];
        }    
    }

    for(int i = 0; i < n; i++) {
        s.push(i);
        dfs(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grape[i][j] << " ";
        }    
        cout << '\n';
    } 
}