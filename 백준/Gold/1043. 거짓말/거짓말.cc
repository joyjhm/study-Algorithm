#include<iostream>
#include<vector>

using namespace std;

bool truth[51];
bool visited[51];
vector<int> party[51];
int n, m;
int num;

void dfs() {


    for(int i = 1; i <= m; i++) {
        if (visited[i]) {
            continue;
        }
        for (int j = 0; j < party[i].size(); j++) {
            
            int target = party[i][j];
            if(truth[target]) {
                visited[i] = true;
                for (int k = 0; k < party[i].size(); k++) {
                    truth[party[i][k]] = true;
                    dfs();
                }
            }
        }
    }
}


int main() {

    cin >> n >> m;
    int temp;
    cin >> num;

    if (num != 0) {
        for (int i = 0; i < num; i++) {
            cin >> temp;
            truth[temp] = true;
        }
    }

    for (int i = 1; i <= m; i++) {
        cin >> num;
        for (int j = 0; j < num; j++) {
            cin >> temp;
            party[i].push_back(temp);
        }
    }

    dfs();

    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        bool plus = true;
        for (int j = 0; j < party[i].size(); j++) {
            if(truth[party[i][j]]) {
                plus = false;
                break;
            }
        }
        if(plus) {
            cnt++;
        }
    }

    cout << cnt;
}