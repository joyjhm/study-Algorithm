#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        int result = 0;
        int n;
        cin >> n;
        vector<int> students(n + 1);
        vector<int> team(n + 1, 0); 
        for (int i = 1; i <= n; i++) {
            cin >> students[i];
        }

        for (int i = 1; i <= n; i++) {
            if(team[i] > 0) {
                continue;
            }

            stack<int> s;
            vector<bool> b(n + 1, false);
            s.push(i);
            b[i] = true;

            while(!s.empty()) {
                int cur = s.top();
                int target = students[cur];

                if(b[target] == true) {
                    team[target] = 1;
                    while(s.top() != target) {
                        team[s.top()] = 1;
                        s.pop();
                    }
                    s.pop();

                    while(!s.empty()) {
                        if(team[s.top()] == 0) {
                            team[s.top()] = 2;
                            result++;
                        }
                        s.pop();
                    }
                }
                else if(team[target] > 0) {
                    while(!s.empty()) {
                        if(team[s.top()] == 0) {
                            team[s.top()] = 2;
                            result++;
                        }
                        s.pop();
                    }
                } else {
                    b[target] = true;
                    s.push(target);
                }

            }

        }

        cout << result << '\n';

    }
}