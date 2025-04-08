#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<vector<int>> v(3, vector<int>(3));
int total_row = 3;
int total_col = 3;

bool compare(pair<int,int> p1, pair<int,int> p2) {

    if (p1.first == 0) return false;
    if (p2.first == 0) return true;

    if(p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}


vector<vector<int>> setRow(int row) {

    vector<vector<int>> new_v(row);
    int total_size = 0;
    for (int i = 0; i < row; i++) {
        vector<pair<int,int>> cnt(101, {0,0});

        int sort_size = 0;
        for (int j = 0; j < v[i].size(); j++) {
            if(v[i][j]) {
                cnt[v[i][j]].first = v[i][j];
                if(cnt[v[i][j]].second == 0) {
                    sort_size++;
                }

                cnt[v[i][j]].second++;
            }
        }

        sort(cnt.begin(), cnt.end(), compare);

        for (int j = 0; (j < sort_size && j < 50); j++) {
            new_v[i].push_back(cnt[j].first);
            new_v[i].push_back(cnt[j].second);
        }

        total_size = max(sort_size, total_size);
    }

    total_col = total_size * 2;

    for (int i = 0; i < row; i++) {
        while(new_v[i].size() < total_col) {
            new_v[i].push_back(0);
        }
    }

    return new_v;
}

vector<vector<int>> setCol(int col) {

    vector<vector<int>> new_v(col);
    int total_size = 0;
    for (int i = 0; i < col; i++) {
        vector<pair<int,int>> cnt(101, {0,0});

        int sort_size = 0;
        for (int j = 0; j < v.size(); j++) {
            if(v[j][i]) {
                cnt[v[j][i]].first = v[j][i];
                if(cnt[v[j][i]].second == 0) {
                    sort_size++;
                }

                cnt[v[j][i]].second++;
            }
        }

        sort(cnt.begin(), cnt.end(), compare);

        for (int j = 0; (j < sort_size && j < 50); j++) {
            new_v[i].push_back(cnt[j].first);
            new_v[i].push_back(cnt[j].second);
        }

        total_size = max(sort_size, total_size);
    }

    total_row = total_size * 2;

    for (int i = 0; i < col; i++) {
        while(new_v[i].size() < total_row) {
            new_v[i].push_back(0);
        }
    }
    return new_v;
}

vector<vector<int>> transform(vector<vector<int>>& old) {
    vector<vector<int>> new_one(total_row, vector<int>(total_col, 0));

    for (int i = 0; i < old.size(); i++) {
        for (int j = 0; j < old[i].size(); j++) {
            if (j < total_row && i < total_col) {
                new_one[j][i] = old[i][j];
            }
        }
    }

    return new_one;
}

int main() {

    int r, c, k;
    cin >> r >> c >> k;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> v[i][j];
        }
    }


    if (r - 1 < v.size() && c - 1 < v[0].size() && v[r - 1][c - 1] == k) {
        cout << 0;
        return 0;
    }

    int times = 0;
    int result = -1;

    while(times++ < 100) {
        if(total_row >= total_col) {
            v = setRow(total_row);
        }
        else {
            v = setCol(total_col);
            v = transform(v);
        }

        if (r - 1 < v.size() && c - 1 < v[0].size() && v[r - 1][c - 1] == k) {
            result = times;
            break;
        }
        
    }

    cout << result;
}