#include<iostream>
#include<map>
using namespace std;

int x[1000000];

map<int, int> m;

int n;
int main() {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        m[x[i]] = 1;
    }
    int sum = 0;
    for(auto iter = m.begin(); iter != m.end(); ++iter) {
        int key = iter -> first;
        m[key] = sum;
        sum++; 
    }
    for(int i = 0; i < n; i++) {
        cout << m[x[i]] << " ";
    }
}