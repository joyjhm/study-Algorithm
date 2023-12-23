#include <iostream>

using namespace std;

int a[1001][2];

int main() {

    int n, number;
    cin >> n;
    int result = 0;
    int max = 0;
    for (int i = 1; i <= n; i++) {
        cin >> number;
        a[i][0] = number;
    }

    for (int i = 1; i <= n; i++) {

        for (int j = 0; j < i; j++) {
            if (a[j][0] < a[i][0]) {
                if (a[i][1] < a[j][1] + 1)
                    a[i][1] = a[j][1] + 1;
            }

        }
        if (max < a[i][1]) {
            max = a[i][1];
        }
    }

    cout << max;
}