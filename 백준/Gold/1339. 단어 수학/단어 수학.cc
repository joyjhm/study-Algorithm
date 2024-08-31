#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int alp[26];
int n;

bool compare(int& a, int& b) {
    return a > b;
}

int main() {

    cin >> n;


    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        int len = str.length() - 1;
        int pow = 1;

        for (int j = len; j >= 0; j--) {
            alp[str[j] - 'A'] += pow;
            pow *= 10;
        }
    }

    sort(alp, alp + 26, compare);

    int val = 9;
    int result = 0;
    for (int i = 0; i < 26; i++) {
        if(alp[i]) {
            result += alp[i] * val;
            val--;
        }
    }


    cout << result;
}