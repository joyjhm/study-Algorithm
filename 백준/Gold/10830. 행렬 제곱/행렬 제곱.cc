#include<iostream>
#include<cmath>
using namespace std;

int n;
long long b;
int arr1[5][5];
int arr2[5][5];
int temp[5][5];
int ans[5][5];


void dot(int arr1[5][5], int arr2[5][5]) {

    int temp[5][5] = {0,};
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                temp[i][j] += arr1[i][k] * arr2[k][j];
            }
            temp[i][j] %= 1000;
        }
    }

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr1[i][j] = temp[i][j];
        }
    }
}



int main() {
    
    cin >> n >> b;
    int root = sqrt(b);
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr1[i][j];
        }
        ans[i][i] = 1;
    }

    while(b > 0) {
        if(b % 2 == 1) {
            dot(ans, arr1);
        }
        dot(arr1, arr1);
        b /= 2;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }

}