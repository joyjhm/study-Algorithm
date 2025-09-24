#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int button[10001];
int light[10001];
int idx[10001];
int dp[10001];
int parent[10001];

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> button[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> light[i];
        idx[light[i]] = i;
    }

    vector<int> pos(n);
    for (int i = 0; i < n; i++) pos[i] = idx[button[i]];


    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }

    int best = 0;
    int best_idx = 0;

    vector<int> seq;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if(pos[i] > pos[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if(dp[i] > best) {
            best = dp[i];
            best_idx = i;
        }
    }


    for (int cur = best_idx; cur != -1; cur = parent[cur]) seq.push_back(light[pos[cur]]);
        reverse(seq.begin(), seq.end());


    sort(seq.begin(), seq.end());

    cout << best << '\n';

    for (int i = 0; i < seq.size(); i++) {
        cout << seq[i] << " ";
    }
}