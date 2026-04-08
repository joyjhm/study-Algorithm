#include<cmath>

using namespace std;

int gcd(int a, int b) { 

    if(a < b) {
        int tmp = b;
        b = a;
        a = tmp;
    }
    while(b != 0) {
        int rest = a % b;
        a = b;
        b = rest;
    }
    return a;
}


long long solution(int w,int h) {

   long long answer = (long long)w * h - (w + h - gcd(w, h));


    return answer;
}