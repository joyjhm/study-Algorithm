#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define INF 2000000000

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> solution(n);
    
    for (int i = 0; i < n; i++) {
        cin >> solution[i];
    }

    sort(solution.begin(), solution.end());

    int start = 0;
    int end = n - 1;
    int diff = INF;
    int result1, result2;

    while(start < end) {
        if(abs(solution[start] + solution[end]) < diff) {
            result1 = solution[start];
            result2 = solution[end];
            diff = abs(solution[start] + solution[end]);

        } 

        if(abs(solution[start] + solution[end - 1]) < abs(solution[start + 1] + solution[end])) {
            end--;
        } else {
            start++;
        }
    }

    cout << result1 << " " << result2;

}




