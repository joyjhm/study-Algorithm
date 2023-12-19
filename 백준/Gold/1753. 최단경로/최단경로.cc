#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;



int v, e, k;
int start, dep, weight;

priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
vector<pair<int, int>> node[20001];
int result[20001];
bool visited[20001];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> e;
    cin >> k;

    for(int i = 0; i < e; i++) {
        cin >> start >> dep >> weight;
        node[start].push_back(make_pair(weight, dep));
    }
    pq.push(make_pair(0,k));
    while(!pq.empty()) {    
        pair<int, int> p = pq.top();
        pq.pop();
        int start_w = p.first;
        int start_node = p.second;
        if(result[start_node] == 0){
            result[start_node] = start_w;
        }
        if(!visited[start_node]) {
            visited[start_node] = true;
            for(int i = 0; i < node[start_node].size(); i++) {
                int dep_w = node[start_node][i].first;
                int dep_node = node[start_node][i].second;
                pq.push(make_pair(dep_w + result[start_node], dep_node));

            }
        }

    }

    for (int i = 1; i <= v; i++) {
        if(i == k) {
            cout << 0 << '\n';
        }
        else if (result[i] == 0) {
            cout << "INF" << '\n';
        }
        else {
            cout << result[i] << '\n';
        }
    }
}