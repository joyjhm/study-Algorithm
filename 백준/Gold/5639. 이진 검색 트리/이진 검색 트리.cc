#include<iostream>
#include<vector>
using namespace std;


int node[10000];


void postOrder(int start, int end) {
    
    if(start >= end) {
        return;
    }
    if (start == end - 1) {
        cout << node[start] << '\n';
        return;
    }
    int idx = start + 1;
    while(idx < end) {
        if (node[start] < node[idx]){
            break;
        }
        idx++;
    }

    postOrder(start + 1, idx);
    postOrder(idx, end);
    cout << node[start] << '\n';
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int num;
    int index = 0;
    while(cin >> num) {
        node[index++] = num;
    }

    postOrder(0, index);

   
}