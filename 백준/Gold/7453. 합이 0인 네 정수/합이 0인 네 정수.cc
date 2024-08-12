#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {

    int n;
    cin >> n;

    vector<int> arr1(n * n);
    vector<int> arr2(n * n);

    vector<int> A(n);
    vector<int> B(n);
    vector<int> C(n);
    vector<int> D(n);

    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        A[i] = a;
        B[i] = b;
        C[i] = c;
        D[i] = d;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr1[i * n + j] = A[i] + B[j];
            arr2[i * n + j] = C[i] + D[j];
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int start = 0;
    int end = n * n - 1;

    long long cnt = 0;

    while(start < n * n && end >= 0) {
        int sum = arr1[start] + arr2[end];

        if(sum > 0) {
            end--;
        }
        else if(sum < 0) {
            start++;
        } else {
            int tmp1 = arr1[start];
            int tmp2 = arr2[end];
            long long arr1Cnt = 0;
            long long arr2Cnt = 0;
            
            while(start < n * n && arr1[start] == tmp1) {
                start++;
                arr1Cnt++;
            }

            while(end >= 0 && arr2[end] == tmp2) {
                end--;
                arr2Cnt++;
            }

            cnt += arr1Cnt * arr2Cnt;
        }
    }

    cout << cnt;
}