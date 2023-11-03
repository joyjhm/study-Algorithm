/*
L = (a % 1000) * 10 + (a / 1000);
R = a / 10 + (a % 10) * 1000;
*/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

bool visited[10000];    

int a,b;
int D(int a) {
    return (a * 2) % 10000;
}

int S(int a) {
    a = a - 1;
    if (a < 0) {
        a = 9999;
    }
    return a;
}

int L(int a) {
    int temp[4];
    for(int i = 1; i <= 3; i++) {
        temp[3 - i] = a % 10;
        a = a / 10;
    }
    temp[3] = a % 10;
    a = a / 10;
    
    return ((temp[0] * 10 + temp[1]) * 10 + temp[2]) * 10 + temp[3];
}

int R(int a) {
    int temp[4];
    temp[0] = a % 10;
    a = a / 10;
    for(int i = 3; i > 0; i--) {
        temp[i] = a % 10;
        a = a / 10;
    }

    return ((temp[0] * 10 + temp[1]) * 10 + temp[2]) * 10 + temp[3];
}

string bfs(int a, int b) {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, string>> q;
    q.push(make_pair(a, ""));
    visited[a] = true;
    string str;
    while(!q.empty()) {
        int len = 10000;
        int n = q.front().first;
        string str = q.front().second;

        string ll;
        if(n == b) {

            return str;
        }
        q.pop();
        int d_num = D(n);
        int s_num = S(n);
        int l_num = L(n);
        int r_num = R(n);
        if(!visited[d_num]) {
            q.push(make_pair(d_num, str + "D"));
            visited[d_num] = true;
        }
        if(!visited[s_num]){
            q.push(make_pair(s_num, str + "S"));    
            visited[s_num] = true;
        }
        if(!visited[l_num]){
            q.push(make_pair(l_num, str + "L"));    
            visited[l_num] = true;
        }
        if(!visited[r_num]){
            q.push(make_pair(r_num, str + "R"));    
            visited[r_num] = true;
        }

    }
    return str;

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        
        string result = bfs(a, b);
        cout << result << "\n";
    }    
}
