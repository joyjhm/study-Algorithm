#include<iostream>
#include <numeric>
using namespace std;

int m,n,x,y, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        cin >> m >> n >> x >> y;
        bool isPossible = false;
        int end = lcm(m,n);
        int first = x;
        int second = x;
        int result = x;
        while(result <= end) {
            while(second > n) {
                second = second - n;
            }
            if(first == x && second == y) {
                isPossible = true;
                break;
            }
            second += m;
            result += m;

        }
        if(isPossible) {
            cout << result <<'\n';
            }
        else{
            cout << -1 << '\n';
        }
    }

}