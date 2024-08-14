#include <iostream>
#include <vector>
using namespace std;

struct Shark {
    int y;
    int x;
    int speed;
    int dir;
    int size;
    bool isPresent = true;
};

int arr[101][101];
int move_arr[101][101];
vector<Shark> shark_list;
int result = 0;

int main() {

    int row, col, m;
    cin >> row >> col >> m;

    shark_list.push_back({0,0,0,0,0, false});

    for (int i = 1; i <= m; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        shark_list.push_back({r,c,s,d,z, true});
        arr[r][c] = i;
    }

    for (int i = 1; i <= col; i++) {

        for (int j = 1; j <= row; j++) {
            if(arr[j][i]) {
                int idx = arr[j][i];
                arr[j][i] = 0;
                shark_list[idx].isPresent = false;
                result += shark_list[idx].size;
                break;
            }
        }

        for (int j = 1; j <= m; j++) {
            if(!shark_list[j].isPresent) {
                continue;
            }

            int y = shark_list[j].y;
            int x = shark_list[j].x;

            arr[y][x] = 0;                
            
            int speed = shark_list[j].speed;
            int dir = shark_list[j].dir;

            while(speed) {
                if(dir == 1) {
                    if (y - speed <= 0) {
                        speed -= y;
                        y = 2;
                        dir = 2;
                    } else {
                        y -= speed;
                        speed = 0;
                    }

                }
                else if(dir == 2) {
                    if(y + speed > row) {
                        speed -= (row + 1) - y;
                        y = row - 1;
                        dir = 1;
                    }
                    else {
                        y += speed;
                        speed = 0;
                    }
                }
                else if(dir == 3) {
                    if (x + speed > col) {
                        speed -= (col + 1) - x;
                        x = col - 1;
                        dir = 4;
                    } else {
                        x += speed;
                        speed = 0;
                    }
                }
                else if(dir == 4) {
                    if (x - speed <= 0) {
                        speed -= x;
                        x = 2;
                        dir = 3;
                    } else {
                        x -= speed;
                        speed = 0;
                    }
                }

            }


            if(move_arr[y][x]) {
                int idx = move_arr[y][x];
                if(shark_list[idx].size < shark_list[j].size) {
                    move_arr[y][x] = j;
                    shark_list[idx].isPresent = false;                
                }
                else {
                    shark_list[j].isPresent = false;
                }
            } else {
                move_arr[y][x] = j;
            }
            shark_list[j].dir = dir;
            shark_list[j].y = y;
            shark_list[j].x = x;
        }

        for (int j = 1; j <= m; j++) {

            if(!shark_list[j].isPresent) {
                continue;
            }

            int y = shark_list[j].y;
            int x = shark_list[j].x;
            move_arr[y][x] = 0;
            arr[y][x] = j;

        }
    }


    cout << result;
}