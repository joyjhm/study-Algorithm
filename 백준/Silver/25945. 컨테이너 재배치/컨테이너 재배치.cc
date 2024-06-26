#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> 

using namespace std;



int main() {

    int n;
    cin >> n;
    int sum = 0;
    vector<int> container(n);

    for (int i = 0; i < n; i++) {
        cin >> container[i];
        sum += container[i];
    }

    int up = 0;
    int down = 0;

    int target1 = sum / n; 
    int target2 = target1 + 1;

    for (int i = 0; i < n; i++) {

        if(container[i] > target2) {
            up += container[i] - target2;
        }

        else if (container[i] < target1) {
            down += target1 - container[i];
        }
    }

    int result = max(up, down);
    
    cout << result;

}