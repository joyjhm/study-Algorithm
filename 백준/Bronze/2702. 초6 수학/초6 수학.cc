#include <iostream>

using namespace std;

int gcd(int a, int b) {

    int tmp;
    if(b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }

}

int lcd(int a, int b, int g) {

    return a * b / g;
}

int main() {
    
    int t, a, b;
    cin >> t;

    while(t--) {
        cin >> a >> b;
        if(b > a) {
            int tmp;
            tmp = b;
            b = a;
            a = tmp;
        }

        int g = gcd(a, b);
        int l = lcd(a, b, g);

        cout << l << " " << g << '\n';
    }

}
