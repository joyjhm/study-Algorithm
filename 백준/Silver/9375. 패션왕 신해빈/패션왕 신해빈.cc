#include<iostream>
#include<string>
#include<map>
using namespace std;

int t;
string cloth;
string type;

int main() {
    cin >> t;
    while(t--) {
        map<string, int> m;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> cloth >> type;
            m[type] += 1;
        }
    int result = 1;
    for(auto iter = m.begin(); iter != m.end(); iter++) {   
        result *= (iter->second + 1);
    }
    cout << result - 1 << '\n';
    }
}