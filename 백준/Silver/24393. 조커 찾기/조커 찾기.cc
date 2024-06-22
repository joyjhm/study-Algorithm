#include <iostream>
#include <deque>
using namespace std;


int cur = 0;
int idx = 1;
int result = 1;


int right_merge(bool isRight, int move) {

    if(isRight) {
        if(idx > move) {
            idx = idx - move;

        }
        else if(idx <= move && idx != 0) {
            result = cur + idx;
            idx = 0;
        }
    } 

    return move;
    
}

int left_merge(bool isRight, int move) {

    if(!isRight) {
        if(idx > move) {
            idx = idx - move;
        }
        else if(idx <= move && idx != 0) {
            result = cur + idx;
            idx = 0;
        }
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

        bool isRight;
        int right = 14;
        int left = 13;

        idx = result;

        if (idx > 13) {
            idx -= 13;
            isRight = true;
        } else {
            isRight = false;
        }
        int cnt = 0;
        while (cur != 27) {
            int tmp;
            cin >> tmp;

            if(cnt % 2 == 0) {
                cur += right_merge(isRight, tmp);
            } else {
                cur += left_merge(isRight, tmp);

            }
            cnt++;
        }

        cur = 0;
    }

    cout << result;
}

