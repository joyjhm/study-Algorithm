#include <iostream>

using namespace std;

int main() {
    int sum, sub;
    cin >> sum >> sub;

    if ((sum + sub) % 2 == 0) {
        int a = (sum + sub) / 2;
        int b = sum - a;
        if (a < 0 || a < b || b < 0) {
            cout << -1;
        } else {
            cout << a << " " << b;
        }


    } else {
        cout << -1;
    }
}