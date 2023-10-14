#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int tree[1000000];
int n, m;

long long getTree(int mid) {
    long long result = 0;
    for(int i = 0; i < n; i++) {
        if(mid < tree[i]) {
            result += tree[i] - mid;
        }
    }
    return result;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> tree[i];
    }

    int max_tree = 0;
    for(int i = 0; i < n; i++) {
        if(max_tree < tree[i]) {
            max_tree = tree[i];
        }
    }

    int start = 0;
    int end = max_tree;
    int mid;
    long long bring_tree;
    int result = 0;
    while(start<=end) {
        mid = (start + end) / 2;
        bring_tree = getTree(mid);
        if(bring_tree < m) {
            end = mid - 1;
        }
        else {
            result = mid; 
            start = mid + 1;
        }
    }
    cout << result;
}