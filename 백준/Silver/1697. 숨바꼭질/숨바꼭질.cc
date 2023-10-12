#include<iostream>
#include<queue>
using namespace std;

int grape[100001];
bool visited[100001];
int n, k;
int op[2] = {1, -1};
queue<int> q;

void visitCheck(int dn) {
    if(dn <= 100000 && dn >= 0 && (!visited[dn])) {
        grape[dn] = grape[n] + 1;
        visited[dn] = true;
        q.push(dn);
    }
}

int main() {
    cin >> n >> k;
    int result = 0;
    q.push(n);
    visited[n] = true;
    while(true) {
        n = q.front();
        int dn;
        q.pop();
        for(int i = 0; i < 3; i++) {
            if(i < 2) {
                dn = n + op[i];
            }
            else {
                dn = n * 2;
            }
            visitCheck(dn);
        }

        if (visited[k]) {
            cout << grape[k];
            break;
        }
    }
}