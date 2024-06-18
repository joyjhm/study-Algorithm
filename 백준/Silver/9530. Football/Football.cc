#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2) {

    return p1.first - p1.second > p2.first - p2.second;
}

int main() {

    int n, g;
    cin >> n >> g;
    vector<pair<int,int>> result(n);
    for (int i = 0; i < n; i++) {
        cin >> result[i].first >> result[i].second;
    }

    sort(result.begin(), result.end(), compare);

    int score = 0;


    for (int i = 0; i < n; i++) {
        if(result[i].first > result[i].second) {
            score += 3;
        }
        else if(result[i].first == result[i].second) {
            if(g > 0) {
                score += 3;
                g--;
            } else {
                score += 1;
            }
        } else{
            if (result[i].second - result[i].first + 1 <= g) {
                score += 3;
                g = g - (result[i].second - result[i].first + 1);
            }
            else if(result[i].second - result[i].first == g) {
                score += 1;
                g = 0;
            } else {
                score += 0;
            }
        }
    }

    cout << score;

}
