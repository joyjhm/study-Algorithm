#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int n = players.size();

    queue<int> q;

    for (int i = 0; i < n; i++) {
        while(!q.empty() && q.front() <= i) {
            q.pop();
        }
        while((q.size() + 1) * m <= players[i]) {
            q.push({i + k});
            answer++;
        }

    }

    return answer;
}