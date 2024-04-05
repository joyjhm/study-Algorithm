#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;

        int diff = y - x;

        int result = 0;
        int idx = 1;

        while(idx * 2 <= diff) {
            diff -= idx * 2;
            result += 2;
            idx++;
        }

        if (0 < diff && diff <= idx) {
            result++;
        }
        else if (idx < diff && diff < idx * 2) {
            result += 2;
        }

        cout << result << '\n';
    }

}