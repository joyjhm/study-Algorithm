#include <iostream>
#include <string>
#include <vector>

using namespace std;

void push(int first, int second, vector<vector<int>> &answer) {
    
    cout << first << " " << second << '\n';
    vector<int> v;
    v.push_back(first);
    v.push_back(second);
    answer.push_back(v);
}

void hanoi(int n, int start, int end, vector<vector<int>> &answer) {
    
    if (n == 1) {
        push(start, end, answer);
        return;
    }
    int temp;
    for (int i = 1; i <= 3; i++) {
        if (i == start || i == end) {
            continue;
        }
        temp = i;
    }
    
    hanoi(n - 1, start, temp, answer); 
    push(start, end, answer);
    hanoi(n - 1, temp, end, answer);

}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
 
    hanoi(n, 1, 3, answer);
    return answer;
}