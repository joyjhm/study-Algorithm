#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
int m;
bool broken[10];
int result = 0;


bool compare(int x) {
    bool isFirst = true;
    int num = x;
    while(x != 0 || isFirst) {
        isFirst = false;
        if(broken[x % 10]){
            return false;
        }
        x = x / 10;
    }
    result = num;
    return true;
}

int main() {
    cin >> n >> m;
    int a;
    int case1 = 0;
    int case2 = 0;

    for (int i = 0; i < m; i++) {
        cin >> a;
        broken[a] = true;
    }
    int target1 = n;
    int target2 = n;
    int target3 = 100;
    if(m != 10){

        while(!(compare(target1) || compare(target2))) {   
            
            target1--;
            if(target1 < 0) {
                target1 = 0;
            }
            target2++;
            case1++;
        }
        bool isFirst = true;
        while(result != 0 || isFirst) {
            isFirst = false;
            result = result / 10;
            case1++;
        }

    }
    else{
        case1 = 5000000;
    }
    case2 = abs(n - 100);
    cout << min(case1,case2);
    
}