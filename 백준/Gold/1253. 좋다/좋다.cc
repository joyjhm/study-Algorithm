#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {

    int n;
    cin >> n;
    map<int,int> good;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int answer = 0;
    for (int i = 0; i < n; i++) {
        int target = arr[i];
        int left = 0;
        int right = n - 1;
        while (left < right) {
            if(left == i) {
                left++;
                continue;
            }
            else if(right == i) {
                right--;
                continue;
            }

            if(arr[left] + arr[right] < target) {
                left++;
            }
            else if (arr[left] + arr[right] > target) {
                right--;
            }
            else {
                answer++;
                break;
            }
        }
    }

    cout << answer;
}