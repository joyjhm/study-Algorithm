#include<iostream>

using namespace std;

int rgb[3];
int house[1001][3];

int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> rgb[0] >> rgb[1] >> rgb[2];

        house[i][0] = min(house[i - 1][1], house[i - 1][2]) + rgb[0];
        house[i][1] = min(house[i - 1][0], house[i - 1][2]) + rgb[1];
        house[i][2] = min(house[i - 1][0], house[i - 1][1]) + rgb[2];
    }

    cout << min(min(house[n][0], house[n][1]), house[n][2]);

}