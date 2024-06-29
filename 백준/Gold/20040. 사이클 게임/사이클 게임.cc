#include <iostream>
#include <vector>
using namespace std;


int parent[500000];

int find(int x) {

    if(parent[x] == x) {
        return x;
    }
    else {
        return parent[x] = find(parent[x]);
    }
}

bool uni(int x, int y) {

    x = find(x);
    y = find(y);

    if (x < y) {
        parent[y] = parent[x];
        return false;
    }
    else if(y < x) {
        parent[x] = parent[y];
        return false;
    }
    return true;
}



int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int result;
    bool isCycle = false;

    for (int i = 1; i <= m; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        if(uni(n1, n2)) {
            result = i;
            isCycle = true;
            break;
        }
    }

    if(isCycle) {
        cout << result;
    }
    else {
        cout << 0;

    }


}
