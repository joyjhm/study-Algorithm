#include <iostream>
#include <deque>
using namespace std;


int cur = 0;
int result = 1;

int merge(int &idx, int move) {

    if(idx > move) {
        idx = idx - move;
    }
    else if(idx <= move && idx != 0) {
        result = cur + idx;
        idx = 0;
    }

    return move;
}



int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;


    for (int i = 0; i < n; i++) {

        int right_idx, left_idx;    
        left_idx = right_idx = 0;

        if (result > 13) {
            right_idx = result - 13;

        } else {
            left_idx = result;
        }
        int cnt = 0;
        while (cur != 27) {
            int tmp;
            cin >> tmp;

            if(cnt % 2 == 0) {
                cur += merge(right_idx, tmp);
            } else {
                cur += merge(left_idx, tmp);

            }
            cnt++;
        }

        cur = 0;
    }

    cout << result;
}

