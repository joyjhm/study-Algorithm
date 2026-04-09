#include <string>
#include <vector>
#include <iostream>

using namespace std;

int n, m;
int opened = 0;

vector<vector<int>> rotate(vector<vector<int>>& key) {
    
    vector<vector<int>> rotated(m, vector<int>(m));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            rotated[j][m - 1 - i] = key[i][j];
        }
    }

    return rotated;
}

bool check(int y, int x, vector<vector<int>>& key, vector<vector<int>>& lock, int k) {
    
    int cnt = 0;

    for (int i = y; i < y + m; i++) {
        for (int j = x; j < x + m; j++) {
            if(i >= n || j >= n || i < 0 || j < 0)
                continue;
            
            if(lock[i][j] == 0 && key[i - y][j - x] == 1) {
                cnt++;
            } 
            else if(lock[i][j] == 1 && key[i - y][j - x] == 1) {
                return false;
            }
        }
    }

    return opened == cnt;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    n = lock.size();
    m = key.size();

    vector<vector<int>> rotated = key;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(lock[i][j] == 0) {
                opened++;
            }
        }
    }

    for (int k = 0; k < 4; k++) {
        for (int i = -m; i < n; i++) {
            for (int j = -m; j < n; j++) {
                if(check(i, j, rotated, lock, k)) {
                    return true;
                }
            }
        }
        rotated = rotate(rotated);
    }

    return false;
}