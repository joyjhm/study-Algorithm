#include<iostream>
#include<cstdlib>
using namespace std;

int n, x;
int sizes = 0;
int heap[100000];

bool isMin(int x, int y) {
    int abs_x = abs(x);
    int target = abs(y);
    if(abs_x < target) {
        return true;
    }
    else if(abs_x == target && x < y) {
        return true;
    }
    else {
        return false;
    }
}

void push(int x) {
    sizes++;
    int index = sizes;
    while(isMin(x, heap[index / 2])) {
        heap[index] = heap[index / 2];
        index /= 2;
    }
    heap[index] = x;
}

int pop(int x) {

    if (sizes == 0) {
        return 0;
    }
    int root = heap[1];
    int parent = 1;
    int child = 2;
    int value = heap[sizes];
    heap[sizes--] = 0;
    while(child <= sizes) {
        if(child + 1 <= sizes && isMin(heap[child + 1], heap[child])) {
            child++;
        }
        if(isMin(value, heap[child])) {
            break;
        }
        heap[parent] = heap[child];
        parent = child;
        child = parent * 2;
    }
    heap[parent] = value;
    return root;
}

int main() {

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(x == 0){
            cout << pop(x) << '\n';
        }
        else {
            push(x);
        }
    }

}