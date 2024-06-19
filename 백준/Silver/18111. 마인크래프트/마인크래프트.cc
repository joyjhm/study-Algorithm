#include <iostream>
#include <algorithm>

using namespace std;

int map[501][501];

int main() {

    int n, m, b;
    cin >> n >> m >> b;

    int height = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            height = max(map[i][j], height);
        }
    }

    int result_height;
    int result_time = 1000000000;

    while(height >= 0) {

        int remove = 0;
        int add = 0;
        int t = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(map[i][j] >= height) {
                    remove += map[i][j] - height;
                }
                else {
                    add += height - map[i][j];
                }
            }
        }

        if(remove + b < add) {
            height--;
            continue;
        }

        t = remove * 2 + add;

        if (result_time > t) {
            result_time = t;
            result_height = height;
        }

        height--;
    }

    cout << result_time << " " << result_height;

}