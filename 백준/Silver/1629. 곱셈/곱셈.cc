#include<iostream>
#include<cmath>
using namespace std;

unsigned long long a, b, c;

unsigned long long f(unsigned long long a, unsigned long long b) {

    if(b == 0) {
        return 1;
    }
    if(b == 1) {
        return a % c;
    }

    unsigned long long temp = f(a, b / 2);
    if (b % 2 == 0) {
        return  temp * temp % c;
    }
    else {
        return temp * temp % c * a % c;
    }
}

int main() {

    cin >> a >> b >> c;
    unsigned long long temp = a;
    unsigned long long result;
    result = f(a,b);
    cout << result;
}

