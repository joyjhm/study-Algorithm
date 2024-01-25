#include<iostream>

using namespace std;

long long n;
long long matrix[2][2] = {{1,1}, {1,0}};
long long sqaure[2][2] = {{1,0}, {0,1}};


void dot(long long a[2][2], long long b[2][2]) {

    long long tmp[2][2] = {0,};
    for(int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                tmp[i][j] += a[i][k] * b[k][j];
            }
            tmp[i][j] %= 1000000007;
        }
    }

    for(int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a[i][j] = tmp[i][j];
        }
    }

}

int main() {

    cin >> n;

    int arr[2][1] = {{1}, {0}};
    while (n > 0) {
        if(n % 2 == 1) {
            dot(sqaure, matrix);
        }
        dot(matrix, matrix);
        n = n / 2;
    }

    int result = sqaure[1][0];

    cout << result;

}