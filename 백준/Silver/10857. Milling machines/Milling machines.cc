#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int w, s;
    cin >> w >> s;
    int x, y;
    cin >> x >> y;

    vector<vector<int>> workpieces;
    for (int i = 0; i < w; i++) {
        vector<int> v(x);
        for (int j = 0; j < x; j++) {
            cin >> v[j];
        }
        workpieces.push_back(v);
    }

    vector<int> mechine(x, 0);
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < x; j++) {
            int tmp;
            cin >> tmp;
            if(mechine[j] < tmp) {
                mechine[j] = tmp;
            }
        }

    }


    for (int i = 0; i < w; i++) {
        for (int j = 0; j < x; j++) {
            if (y - mechine[j] < workpieces[i][j]) {
                workpieces[i][j] = y - mechine[j];
            }
        }
        
    }

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < x; j++) {
            cout << workpieces[i][j] << " ";
        }
        cout << '\n';
    }

}