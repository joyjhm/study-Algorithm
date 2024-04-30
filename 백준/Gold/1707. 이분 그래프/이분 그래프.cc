#include <iostream>
#include <vector>
#include <queue>
using namespace std;


bool search(vector<int> node[], vector<int>& status, queue<int>& q) {

    bool result = true;

    while(!q.empty()) {
        int cur = q.front();
        int s = status[cur];
        q.pop();

        for (int i = 0; i < node[cur].size(); i++) {
            int next = node[cur][i];
            if(status[next] == 0) {
                status[next] = -s;
                q.push(next);
            }
            else {
                if(status[next] == s) {
                    result = false;
                    break;
                }
            }
        }

        if(!result) {
            break;
        }
    }
    return result;
}


int main() {

    int k;
    cin >> k;
    while(k--) {
        int v, e, v1, v2;
        cin >> v >> e;
        vector<int> node[v + 1];
        vector<int> status(v + 1); //(상태: 0 -> 방문x, 1 -> 집합1, -1-> 집합2)
        for (int i = 0; i < e; i++) {
            cin >> v1 >> v2;
            node[v1].push_back(v2);
            node[v2].push_back(v1);
        }

        queue<int> q;
        while(true) {
            bool isCheck = true;
            bool result = true;
            for (int i = 1; i <= v; i++) {
                if(!status[i]) {
                    q.push(i);
                    status[i] = 1;
                    isCheck = false;
                    break;
                }
            }
            if(!isCheck) {
                result = search(node, status, q);
                if(!result) {
                    cout << "NO" << '\n';
                    break;
                }
            } else {
                cout << "YES" << '\n';
                break;
            }
        }

    }
}

