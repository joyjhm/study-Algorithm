#include<iostream>

using namespace std;

int n,m;
int city[101][101];
int INF = 10000000;
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> m;
    fill(&city[1][1], &city[n][n], INF);

    for (int i = 0; i < m; i++) {
        int start, end, weight;
        cin >> start >> end >> weight;
        if(city[start][end] > weight) {
            city[start][end] = weight;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if(j == k) {
                    city[j][k] = 0;
                    continue;
                }
                if(city[j][k] > city[j][i] + city[i][k]) {
                    city[j][k] = city[j][i] + city[i][k];
                }
            }
        }
    }

    for(int i = 1 ; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(city[i][j] == INF) {
                cout << 0 << " ";
            }
            else {
                cout << city[i][j] << " ";
            }
        }
        cout << '\n';
    }
    
}