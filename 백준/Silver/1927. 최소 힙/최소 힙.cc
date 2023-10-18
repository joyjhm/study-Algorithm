#include<iostream>
#include<vector>

using namespace std;
int arr[100001];
int heap_size, x;
void push() {
    heap_size++;
    int index = heap_size;
    while(index != 1 && arr[index / 2] > x) {
        arr[index] = arr[index / 2];
        index = index / 2;
    }
    arr[index] = x;

}

int pop() {
    if(heap_size == 0) {
        return 0;
    }
    int parent, child, value;
    parent = 1;
    child = 2;
    int remove_value = arr[1];

    value = arr[heap_size]; // value는 옮겨야 할 마지막 원소
    arr[heap_size--] = 0;     // 마지막 원소 삭제         
    // arr[1] = value; // root에 value 값을 집어 넣는다.

    while(child <= heap_size) {
        if(child < heap_size && arr[child] > arr[child + 1]) {
            child++;
        }
        if(value < arr[child]){
            break;
        }
        arr[parent] = arr[child];
        parent = child;
        child *= 2;
    }
    arr[parent] = value;
    return remove_value;
}

int main() {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    heap_size = 0;
    while(n--) {
        cin >> x;
        if(x){
            push();  
        }
        else{
            cout << pop() << '\n';
        }
    }
}