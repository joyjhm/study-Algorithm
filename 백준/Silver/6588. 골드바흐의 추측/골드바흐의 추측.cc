#include <iostream>
#include <cmath>
using namespace std;

bool isNotPrime [1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;

    for (int i = 2; i <= 1000; i++) {
        if(!isNotPrime[i]) {
            for (int j = i * 2; j <= 1000000; j += i) {
                isNotPrime[j] = true;
            }
        }   
    }


    while(true) {
        cin >> n;

        if(!n) {
            break;
        }

        int a = 3;
        int b = n - 3;

        while(a < b) {
            if(!isNotPrime[a] && !isNotPrime[b]) {
                break;
            }
            a++;
            b--;
        }

        cout << n << " = " << a << " + " << b << '\n';
    }
}