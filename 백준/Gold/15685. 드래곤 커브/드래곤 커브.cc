#include <iostream>
#include <vector>
using namespace std;

bool maps[101][101];
int matrix[2][2] = {{0, -1}, {1, 0}};
int arr[2];
int n, x, y, d, g;

void rotate(int target_x, int target_y, int move_x, int move_y) {

    int tx = move_x - target_x;
    int ty = move_y - target_y;

    for (int i = 0; i < 2; i++) {
        arr[i] = matrix[i][0] * tx + matrix[i][1] * ty;
    }

    arr[0] += target_x;
    arr[1] += target_y;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y >> d >> g;
        vector<pair<int,int>> v;
        v.push_back({x,y});
        int target_x = x;
        int target_y = y;
        if(d == 0) {
            target_x++;
        } else if(d == 1) {
            target_y--;
        } else if(d == 2) {
            target_x--;
        } else {
            target_y++;
        }
        v.push_back({target_x, target_y});

        while(g--) {
            
            int v_size = v.size();
            int tmp_x, tmp_y;
            for (int i = 0; i < v_size; i++) {
                if(target_x == v[i].first && target_y == v[i].second) {
                    continue;
                }
                rotate(target_x, target_y, v[i].first, v[i].second);
                v.push_back({arr[0], arr[1]});

                if(x == v[i].first && y == v[i].second) {
                    tmp_x = arr[0];
                    tmp_y = arr[1];
                }
            }
            target_x = tmp_x;
            target_y = tmp_y;
        }

        for (int i = 0; i < v.size(); i++) {
            maps[v[i].first][v[i].second] = true;
        }
    }
    int cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if(maps[i][j] && maps[i + 1][j] && maps[i][j + 1] && maps[i + 1][j + 1]) {
                cnt++;
            }
        }   
    }

    cout << cnt;
}