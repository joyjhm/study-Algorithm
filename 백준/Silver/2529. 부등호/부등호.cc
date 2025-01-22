#include <iostream>
#include <vector>

using namespace std;

char sign[9];
int k;
bool visited[10];
vector<int> v;
bool breaker;

bool compare(int first, int second, char s) {

    if(s == '>') {
        return first > second;
    }
    return first < second;
}

void dfs(int cnt, int start, int add) {
    


    if (cnt == k + 1) {
        for (int i = 0; i <= k; i++) {
            cout << v[i];
        }
        cout << '\n';
        breaker = true;
        return;
    }
    int idx = start;
    while(idx >= 0 && idx <= 9) {
        if(!visited[idx] && !breaker) {
            if(cnt == 0 || compare(v[cnt - 1], idx, sign[cnt - 1])) {
                v.push_back(idx);
                visited[idx] = true;
                dfs(cnt + 1, start, add);
                visited[idx] = false;
                v.pop_back();
            }
        }
        idx += add;
    }


}



int main() {
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> sign[i];
    }

    dfs(0, 9, -1);
    breaker = false;
    dfs(0, 0, 1);
}