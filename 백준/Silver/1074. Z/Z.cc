#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int n,r,c;
    cin >> n >> r >> c;

    int sizes = pow(2,n);
    int first = 0;
    while(sizes != 1) {
        int row, col;
    if(sizes > 2) {
        row = r % (sizes/2);
        col = c % (sizes/2);
    }

    if(r < sizes/2 && c < sizes/2) {

    }
    else if (r < sizes/2 && c >= sizes/2){
        first += (sizes/2) * (sizes/2);
    }
    else if (r >= sizes/2 && c < sizes/2) {
        first += (sizes/2) * (sizes/2) * 2; 
    }
    else {
        first += (sizes/2) * (sizes  /2) * 3;
    }
    sizes /= 2;
    r = row;
    c = col;
    }


    cout << first;
}