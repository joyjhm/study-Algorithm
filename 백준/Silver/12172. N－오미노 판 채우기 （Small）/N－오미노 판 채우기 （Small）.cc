#include <iostream>

using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        int x, r, c;
        cin >> x >> r >> c;

        if(x == 1) {
            cout << "Case #" << i << ": GABRIEL" << '\n';
        }
        else if(x == 2) {
            if ((r * c) % 2 == 1) {
                cout << "Case #" << i << ": RICHARD" << '\n';
            }
            else {
                cout << "Case #" << i << ": GABRIEL" << '\n';
            }
        }
        else if (x == 3) {
            if ((r * c) % 3 != 0) {
                cout << "Case #" << i << ": RICHARD" << '\n';
            }
            else if(r * c == 3) {
                cout << "Case #" << i << ": RICHARD" << '\n';
            }
            else {
                cout << "Case #" << i << ": GABRIEL" << '\n';
            }
        }
        else {
            if(r == 4 && c == 4) {
                cout << "Case #" << i << ": GABRIEL" << '\n';
            }
            else if(r * c == 12) {
                cout << "Case #" << i << ": GABRIEL" << '\n';
            }
            else {
                cout << "Case #" << i << ": RICHARD" << '\n';
            }
        }
    }   
}