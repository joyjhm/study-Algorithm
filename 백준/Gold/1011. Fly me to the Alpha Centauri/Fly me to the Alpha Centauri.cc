#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;

        int diff = y - x;

        int result = 0;

        int tmp  = (int) sqrt(diff);

        if (diff == tmp * tmp) {
            result = tmp * 2 - 1;
        }
        else if (diff <= tmp * tmp + tmp) {
            result = tmp * 2;
        }
        else {
            result = tmp * 2 + 1;
        }

        cout << result << '\n';
    }

}