#include <string>
#include <vector>

using namespace std;

int lcd(int a, int b) {
    
    if (a < b) {
        int tmp = b;
        b = a;
        a = tmp;
    }
    
    int val = 1;
    for (int i = b; i > 0; i--) {
        if(a % i == 0 && b % i == 0) {
           val = i;
            break;
        }
    }
    
    return val;
}

int gcd(int a, int b, int lcd) {
    return (a * b) / lcd;
}

int solution(vector<int> arr) {

    int answer = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        int val = lcd(answer, arr[i]);
        int val2 = gcd(answer, arr[i], val);
        answer = val2;
    }
    
    return answer;
}