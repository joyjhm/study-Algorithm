#include <string>
#include <vector>

using namespace std;


int arr[1001][1001];
int idx = 1;

void first(int y, int x, int n);
void second(int y, int x, int n);
void third(int y, int x, int n);


void first(int y, int x, int n) {
    
    if(n == 0) {
        return;
    }
    
    for (int i = 0; i < n; i++) {
        arr[y][x] = idx;
        idx++;
        y++;
    }
    y--;
    second(y, x + 1, n - 1);
}

void second(int y, int x, int n) {
    
    if(n == 0) {
        return;
    }
    
    for (int i = 0; i < n; i++) {
        arr[y][x] = idx;
        idx++;
        x++;
    }
    x--;
    third(y - 1, x - 1, n - 1);
}
void third(int y, int x, int n) {
    
    if(n == 0) {
        return;
    }
    
    for (int i = 0; i < n; i++) {
        arr[y][x] = idx;
        y--;
        x--;
        idx++;
    }
    y++;
    x++;
    
    first(y + 1, x, n - 1);
}

vector<int> solution(int n) {
    vector<int> answer;
    
    first(1, 1, n);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            answer.push_back(arr[i][j]);
        }
    }
    
    return answer;
}