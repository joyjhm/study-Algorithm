#include <iostream>
#include <cmath>
#define INF 100000000
using namespace std;

int p[3][2];

int main() {

    for (int i = 0; i < 3; i++) {
        cin >> p[i][0] >> p[i][1];
    }

    int temp = p[0][0] * p[1][1] + p[1][0] * p[2][1] + p[2][0] * p[0][1];
    temp = temp - (p[0][1] * p[1][0] + p[1][1] * p[2][0] + p[2][1] * p[0][0]);

    if (temp > 0) {
        cout << 1;
    }
    else if (temp < 0) {
        cout << -1;
    }
    else {
        cout << 0;
    }

}


