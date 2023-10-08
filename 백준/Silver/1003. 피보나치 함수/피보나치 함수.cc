#include<iostream>

using namespace std;

int zero[41];
int one[41];

int main() {

    int t, n;
    cin >> t;

    zero[0] = one[1] = 1;
    zero[1] = one[0] = 0;
    zero[2] = one[2] = 1;
    zero[3] = 1;
    one[3] = 2;

    for (int i = 4; i <= 40; i++) {

        zero[i] = zero[i - 2] + zero[i - 1];
        one[i] = one[i-2] + one[i - 1];
    }

    while (t--) {

        cin >> n;

        cout << zero[n] << " " << one[n] << endl;
    }

}