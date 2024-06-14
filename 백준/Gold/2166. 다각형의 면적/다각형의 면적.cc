#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;


int main() {

    int n;
    cin >> n;
    long long first_x, first_y, prev_x, prev_y;


    cin >> first_x >> first_y;
    prev_x = first_x;
    prev_y = first_y;
    double result = 0;
    for (int i = 1; i < n; i++) {
        long long x, y;

        cin >> x >> y;
        result += prev_x * y;
        result -= x * prev_y;

        prev_x = x;
        prev_y = y;
    }

    result += prev_x * first_y;
    result -= first_x * prev_y;
    
    result = result / 2;

    cout << fixed;
    cout.precision(1);
    cout << abs(result);

}  