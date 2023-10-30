#include<iostream>
#include<map>
using namespace std;

map<string, string> memo;
int n, m;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    string site, password;
    for(int i = 0; i < n; i++) {
        cin >> site >> password;
        memo[site] = password;
    }
    
    for(int i = 0; i < m; i++) {
        cin >> site;
        cout << memo[site] << '\n';
    }
}