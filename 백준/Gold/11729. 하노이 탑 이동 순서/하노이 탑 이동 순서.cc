#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> v;

void hanoi(int n, int start, int dest) {

    if (n == 1) {
        v.push_back({start, dest});
        return;
    }
    int temp;
    for (int i = 1; i <= 3; i++) {
        if (i == start || i == dest) {
            continue;
        }
        temp = i;
    }

    hanoi(n - 1, start, temp);
    v.push_back({start, dest});
    hanoi(n - 1, temp, dest);

}

int main() {
    int n;
    cin >> n;
    hanoi(n, 1, 3);
    
    cout << v.size() << '\n';

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << '\n';
    }

}