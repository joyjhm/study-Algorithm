#include <iostream>

using namespace std;

int games[100][3];

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> games[i][0] >> games[i][1] >> games[i][2];
    }
    int result = 0;
    int rock;
    for (int i = 1; i <= 3; i++) {
        int cnt = 0;
        rock = i;
        for (int j = 0; j < n; j++) {
            if(games[j][0] == rock) {
                rock = games[j][1];
            }
            else if (games[j][1] == rock) {
                rock = games[j][0];
            }

            if(rock == games[j][2]) {
                cnt++;
            }
        }

        if (result < cnt) {
            result = cnt;
        }
    }

    cout << result;
}