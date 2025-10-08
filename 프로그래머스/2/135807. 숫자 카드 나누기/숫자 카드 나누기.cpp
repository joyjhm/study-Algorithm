#include <string>
#include <vector>
#include <iostream>

using namespace std;


int gcd(int a, int b) {
    if (a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    while (b != 0) {
        int rest = a % b;
        a = b;
        b = rest;
    }
    return a;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int n = arrayA.size();
    int m = arrayB.size();
    
    int d = arrayA[0];
    int i;
    // case 1
    for (i = 1; i < n; i++) {
        d = gcd(d, arrayA[i]);
    }
 
    if (d != 1) {
        for (i = 0; i < m; i++) {
            if(arrayB[i] % d == 0) {
                break;
            }
        }
        if(i == m) {
            answer = d;
        }        
    }
    
    d = arrayB[0];

    for (i = 1; i < m; i++) {
        d = gcd(d, arrayB[i]);
    }
    if(d != 1) {
        for (i = 0; i < n; i++) {
            if(arrayA[i] % d == 0) {
                break;
            }
        }
        if(i == n) {
            answer = max(answer, d);
        }
    }

    return answer;
}