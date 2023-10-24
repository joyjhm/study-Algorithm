#include<iostream>
#include<map>
using namespace std;

map<string, int> pokemon1;
map<int, string> pokemon2;


int main() {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    for(int i = 1; i <= n; i++){
        cin >> s;
        pokemon1[s] = i;
        pokemon2[i] = s;
    }

    for (int i = 0; i < m; i++) {
        string input;
        cin >> input;
        if(isdigit(input[0])) {
            int num = stoi(input);
            cout << pokemon2[num] << '\n';
        }
        else {
            cout << pokemon1[input] << '\n';
        }
    }
}