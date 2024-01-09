#include<iostream>

using namespace std;

int r, c, t;
int room[50][50];
int air_cleaner[2];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


void reverse_rotate(int index) {
    
    for(int i = index - 1; i > 0; i--) {
        room[i][0] = room[i - 1][0];
    }
    for(int i = 0; i < c - 1; i++) {
        room[0][i] = room[0][i + 1];
    }
    for(int i = 0; i < index; i++) {
        room[i][c - 1] = room[i + 1][c - 1]; 
    }
    for(int i = c - 1; i > 0; i--) {
        if(i == 1) {
            room[index][i] = 0;
        }
        else {
            room[index][i] = room[index][i - 1];
        }
        
    }
}

void rotate(int index) {

    for(int i = index + 1; i < r - 1; i++) {
        room[i][0] = room[i + 1][0];
    }
    for(int i = 0; i <= c - 1; i++) {
        room[r - 1][i] = room[r - 1][i + 1];
    }
    for(int i = r - 1; i > index; i--) {
        room[i][c - 1] = room[i - 1][c - 1];
    }
    for(int i = c - 1; i > 0; i--) {
        if(i == 1) {
            room[index][i] = 0;
        } else {
            room[index][i] = room[index][i - 1];
        }
    }

}


void spread(int change[50][50]) {

    for(int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(room[i][j] < 5){
                continue;
            }
            else {
                int changeValue = room[i][j] / 5;
                for(int k = 0; k < 4; k++) {
                    int y = i + dy[k];
                    int x = j + dx[k];
                    if(y < 0 || y >= r || x < 0 || x >= c)
                        continue;
                    if(room[y][x] == - 1)
                        continue;
                    change[i][j] -= changeValue;
                    change[y][x] += changeValue;
                }
            }
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            room[i][j] += change[i][j]; 
        }
    }

}

void work() {
    reverse_rotate(air_cleaner[0]); 
    rotate(air_cleaner[1]);
}


int main() {
    
    cin >> r >> c >> t;
    int idx = 0;
    for (int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> room[i][j];
            if(room[i][j] == -1) {
                air_cleaner[idx] = i;
                idx++;
            }
        }
    }

    for(int i = 0; i < t; i++) {
        int change[50][50] = {0,};
        spread(change);
        work();
    }

    int sum = 0;
    for(int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(room[i][j] > 0) {
                sum += room[i][j];
            }
        }
    }

    cout << sum;

}