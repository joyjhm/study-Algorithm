#include<iostream>

using namespace std;

int n, x, y;
int arr[100];
int main() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x >> y;

    int result1 = n * x / 100;

    int result2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= y) {
            result2++;
        }
    }

    cout << result1 << " " << result2;


}