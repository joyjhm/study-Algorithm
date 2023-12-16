#include<iostream>
#include<string>
using namespace std;

int n, m;
int cnt = 0;
string s;
int dp[1000001];
int main() {

    cin >> n;
    cin >> m;
    cin >> s;


    for(int i = 2; i <= m; i++) {
        if(s[i - 2] == 'I' && s[i - 1] == 'O' && s[i] == 'I') {
            dp[i] = dp[i - 2] + 1;
        }
    }

    for(int i = 0; i < m; i++){
        if(dp[i] >= n){
            cnt++;
        }
    }

    cout << cnt;

    
}