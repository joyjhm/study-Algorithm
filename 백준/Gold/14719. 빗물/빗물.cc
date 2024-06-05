#include <iostream>

using namespace std;

int h, w;

int arr[501][501];
int result = 0;
int main() {
    
    cin >> h >> w;

    for (int i = 1; i <= w; i++) {
        int height;
        cin >> height;
        for (int j = h; j > h - height; j--) {
            arr[j][i] = 1;
        }
    }

    for (int i = 1; i <= h; i++) {
        int prev = 0;
        int cnt = 0;
        for (int j = 1; j <= w; j++) {
            if(arr[i][j] == 1) {
                if (prev != 0) {
                    cnt += j - prev - 1;
                }
                prev = j;
            }
        }
        result += cnt;
    }

    cout << result;
}

