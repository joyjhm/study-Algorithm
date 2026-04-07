#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    
    int n = a.size();
    vector<int> leftMin(n);
    vector<int> rightMin(n);

    leftMin[0] = a[0];
    rightMin[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMin[i] = min(a[i], rightMin[i + 1]);
    }

    for (int i = 1; i < n; i++) {
        leftMin[i] = min(leftMin[i - 1], a[i]);        
    }
    
    int answer = 2;

    for (int i = 1; i < a.size() - 1; i++) {
        if(a[i] < leftMin[i - 1] || a[i] < rightMin[i + 1]) {
            answer++;
        }
    }

    return answer;
}