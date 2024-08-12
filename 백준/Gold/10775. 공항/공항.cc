#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;


int main() {

    int g;
    cin >> g;

    int p;
    cin >> p;

    set<int> gate;

    for (int i = 1; i <= g; i++) {
        gate.insert(-i);;
    }

    int cnt = 0;

    bool isEnd = false;

    for (int i = 0; i < p; i++) {
        int plane_num;
        cin >> plane_num;

        auto it = gate.lower_bound(-plane_num);
        if (it == gate.end()) {
            break;
        }

        gate.erase(it);
        cnt++;

    }

    cout << cnt;
}