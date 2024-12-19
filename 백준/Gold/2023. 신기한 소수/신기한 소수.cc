#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<int> v;
int n;

bool isPrime(int num) {

    if(num == 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) {
            return false;
        }
    }
    
    return true;
}

int getNum() {
    int num = 0;
    for (int i = 0; i < v.size(); i++) {
        num += v[i] * pow(10, (v.size() - 1) - i);
    }

    return num;
}

void dfs(int depth) {

    if(n == depth) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
        }
        cout << '\n';
        return;
    }


    for (int i = 1; i <= 9; i++) {
        v.push_back(i);
        if(isPrime(getNum())) {
            dfs(depth + 1);
        }
        v.pop_back();
    }

    return;
}


int main() {

    cin >> n;

    dfs(0);
}