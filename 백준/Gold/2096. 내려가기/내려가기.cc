#include<iostream>
#include<algorithm>

using namespace std;

int previous[2][3];
int arr[3];
int n;
int result_max = 0;
int result_min = 0;
int main() {

    cin >> n;


    for (int i = 1; i <= n; i++) {
        int current[2][3] = {0,};
        for (int j = 0; j < 3; j++) {
            cin >> arr[j];
        }

        current[0][0] = max(previous[0][0], previous[0][1]) + arr[0];
        current[0][1] = max({previous[0][0], previous[0][1], previous[0][2]}) + arr[1];
        current[0][2] = max(previous[0][1], previous[0][2]) + arr[2];
        
        current[1][0] = min(previous[1][0], previous[1][1]) + arr[0];
        current[1][1] = min({previous[1][0], previous[1][1], previous[1][2]}) + arr[1];
        current[1][2] = min(previous[1][1], previous[1][2]) + arr[2];

        result_max = max({current[0][0], current[0][1], current[0][2]});
        result_min = min({current[1][0], current[1][1], current[1][2]});


        for (int y = 0; y < 2; y++) {
            for (int x = 0; x < 3; x++) {
                previous[y][x] = current[y][x];
            }
        }
    }

    cout << result_max << " " << result_min;
}