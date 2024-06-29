#include <iostream>
#include <queue>
using namespace std;

int dy[4] = {-2, -1, 1, 2};
int dx[4] = {1, 2, 2, 1};

bool visited[3][7];




int main() {

    int n, m;
    cin >> n >> m;

    int result = 0;
    int x = 1;

    if (n < 2) {
        result = 1;
    }
    else if (n < 3 && m < 7) {
        result = ((m - 1) / 2) + 1;
    }
    else if(n >= 3 && m < 7) {
        if(m < 4) {
            result = m;
        } else {
            result = 4;
        }
    }
    else if(n < 3 && m >= 7) {
        result = 4;
    }
    else {
        result = 3 + (m - 5);
    }

    cout << result;

}