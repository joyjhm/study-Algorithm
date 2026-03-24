#include <iostream>

using namespace std;

bool isNotPrime[10001];

int main() {
    int t;
    cin >> t;

    for (int i = 2; i <= 100; i++) {
        if(isNotPrime[i]) {
            continue;
        }
        for (int j = i * 2; j <= 10000; j = j + i) {
            isNotPrime[j] = true;
        }
    }

    while(t--) {
        int n;
        cin >> n; 

        int left = n / 2;
        int right = n / 2;

        while(isNotPrime[left] || isNotPrime[right]) {
            left--;
            right++;
        }

        cout << left << " " << right << '\n';
    }
}